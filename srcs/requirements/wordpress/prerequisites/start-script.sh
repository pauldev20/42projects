#!/bin/bash

rm -rf /finished_init

# -------------------------------- CHECK VARS -------------------------------- #
if [[ -z $WORDPRESS_DB_NAME || -z $WORDPRESS_DB_USER || -z $WORDPRESS_DB_PASSWORD || -z $WORDPRESS_DB_HOST || -z $DOMAIN_NAME \
		|| -z $WORDPRESS_TITLE || -z $WORDPRESS_ADMIN_USER || -z $WORDPRESS_ADMIN_PASSWORD || -z $WORDPRESS_ADMIN_EMAIL \
		|| -z $WORDPRESS_USER || -z $WORDPRESS_EMAIL || -z $WORDPRESS_PASSWORD ]]; then
	echo -e "\033[0;31mMissing .env vars!\033[0m"
	exit 1
fi

if ! wp 2> /dev/null ; then
	# ------------------------------ INSTALL WP-CLI ------------------------------ #
	curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp
	chmod 777 /usr/local/bin/wp
fi

if [ ! -f "/var/www/html/wp-config.php" ]; then
	mkdir -p /var/www/html
	cd /var/www/html && rm -rf *
	chmod 777 /var/www/html

	# ---------------------------- DOWNLOAD WORDPRESS ---------------------------- #
	wp core download --path=/var/www/html --allow-root
	mv /wp-config.php /var/www/html/wp-config.php

	# ---------------------------- CONFIGURE WORDPRESS --------------------------- #
	sed -i "s/database_name_here/$WORDPRESS_DB_NAME/g" /var/www/html/wp-config.php
	sed -i "s/username_here/$WORDPRESS_DB_USER/g" /var/www/html/wp-config.php
	sed -i "s/password_here/$WORDPRESS_DB_PASSWORD/g" /var/www/html/wp-config.php
	sed -i "s/localhost/$WORDPRESS_DB_HOST/g" /var/www/html/wp-config.php

	sed -i "s/\<AUTH_KEY_PHRASE\>/$(openssl rand -hex 64)/g" /var/www/html/wp-config.php
	sed -i "s/\<SECURE_AUTH_KEY_PHRASE\>/$(openssl rand -hex 64)/g" /var/www/html/wp-config.php
	sed -i "s/\<LOGGED_IN_KEY_PHRASE\>/$(openssl rand -hex 64)/g" /var/www/html/wp-config.php
	sed -i "s/\<NONCE_KEY_PHRASE\>/$(openssl rand -hex 64)/g" /var/www/html/wp-config.php
	sed -i "s/\<AUTH_SALT_PHRASE\>/$(openssl rand -hex 64)/g" /var/www/html/wp-config.php
	sed -i "s/\<SECURE_AUTH_SALT_PHRASE\>/$(openssl rand -hex 64)/g" /var/www/html/wp-config.php
	sed -i "s/\<LOGGED_IN_SALT_PHRASE\>/$(openssl rand -hex 64)/g" /var/www/html/wp-config.php
	sed -i "s/\<'NONCE_SALT_PHRASE'\>/$(openssl rand -hex 64)/g" /var/www/html/wp-config.php

	wp core install --path=/var/www/html --url=$DOMAIN_NAME --title="$WORDPRESS_TITLE" --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --allow-root
	wp user create $WORDPRESS_USER $WORDPRESS_EMAIL --role=author --user_pass=$WORDPRESS_PASSWORD --path=/var/www/html --allow-root
fi

# ----------------------------- UPDATE WORDPRESS ----------------------------- #
wp plugin update --path=/var/www/html --all --allow-root

# ----------------------------- CONFIGURE PHP-FPM ---------------------------- #
sed -i "s/\/run\/php\/php7\.3-fpm\.sock/wordpress:9000/g" /etc/php/7.3/fpm/pool.d/www.conf

touch /finished_init
echo -e "\033[1;33mFinished Wordpress init!\033[0m"

# ------------------ EXECUTE ALL COMMANDS GIVEN AS ARGUMENTS ----------------- #
exec "$@"
