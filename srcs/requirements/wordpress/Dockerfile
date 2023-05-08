FROM debian:buster

# Metadata
LABEL version="1.0"
LABEL description="wordpress Server"
LABEL author="pgeeser"

# Update and upgrade
RUN apt-get -y update && apt-get -y upgrade

# Install php7.3 and php-fpm php-mysqli
RUN apt-get -y install php7.3 php-mysqli php-fpm curl openssl sendmail

# Clean up
RUN apt-get -y clean

# Copying needed files (dependencies)
COPY ./prerequisites/start-script.sh /start-script.sh
RUN chmod 777 /start-script.sh
COPY ./prerequisites/wpconfig.php /wp-config.php

# Create directory for php socket
RUN mkdir /run/php && chmod 777 /run/php

# Expose only port 9000
EXPOSE 9000

# Healthcheck to check if wordpress is initialized and ready
HEALTHCHECK  --interval=10s --timeout=3s --retries=30 \
  CMD test -f /finished_init || exit 1

# Defaults that need to be set before starting wordpress
ENTRYPOINT [ "/start-script.sh" ]

# CMD for starting wordpress
CMD [ "php-fpm7.3", "--nodaemonize" ]
