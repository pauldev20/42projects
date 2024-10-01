FROM debian:buster

# --------------------------------- METADATA --------------------------------- #
LABEL version="1.0"
LABEL description="wordpress Server"
LABEL author="pgeeser"

# ------------------------ UPDATE, UPGRADE AND INSTALL ----------------------- #
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install php7.3 php-fpm php-mysqli mariadb-client curl
RUN apt-get -y clean
RUN curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp && chmod 777 /usr/local/bin/wp

# ----------------------- COPY DEPENDENCIES AND CONFIGS ---------------------- #
COPY ./prerequisites/start-script.sh /start-script.sh
RUN chmod 777 /start-script.sh
COPY ./prerequisites/www.conf /etc/php/7.3/fpm/pool.d/www.conf

# ------------------------------ PORT FORWARDING ----------------------------- #
EXPOSE 9000

# -------------------------------- HEALTHCHECK ------------------------------- #
HEALTHCHECK  --interval=10s --timeout=3s --retries=30 \
  CMD test -f /finished_init || exit 1

# Create directory for php socket
RUN mkdir /run/php && chmod 777 /run/php

# Defaults that need to be set before starting wordpress
ENTRYPOINT [ "/start-script.sh" ]

# CMD for starting wordpress
CMD [ "php-fpm7.3", "--nodaemonize" ]
