#!/bin/bash

# -------------------------------- CHECK VARS -------------------------------- #
if [[ -z $DOMAIN_NAME ]]; then
	echo -e "\033[0;31mMissing .env vars!\033[0m"
	exit 1
fi

# -------------------------- CREATE SSL CERTIFICATE -------------------------- #
# C: Country Name (2 letter code)
# ST: State or Province Name (full name)
# L: Locality Name (eg, city)
# O: Organization Name (eg, company)
# OU: Organizational Unit Name (eg, section)
# CN: Common Name (e.g. pgeeser.42.fr)
if [ ! -f "/etc/ssl/private/custom_key.pem" ]; then
	openssl	req -x509 -newkey rsa:4096 -keyout /etc/ssl/private/custom_key.pem -out /etc/ssl/certs/custom_cert.pem -sha256 -days 3650 -nodes\
			-subj "/C=DE/ST=Baden-Wuerttemberg/L=Stuttgart/O=42/OU=pgeeser/CN=pgeeser.42.fr"
fi

# ------------------------------ NGINX CONFIG ------------------------------- #
sed -i "s/\<domainname\>/$DOMAIN_NAME/g" /etc/nginx/sites-enabled/custom

echo -e "\033[1;33mFinished NGINX init!\033[0m"

# ------------------ EXECUTE ALL COMMANDS GIVEN AS ARGUMENTS ----------------- #
exec "$@"
