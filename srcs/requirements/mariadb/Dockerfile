FROM debian:buster

# Metadata
LABEL version="1.0"
LABEL description="MariaDB Server"
LABEL author="pgeeser"

# Update and upgrade
RUN apt-get -y update && apt-get -y upgrade

# Install mariadb
RUN apt-get -y install mariadb-server

# Clean up
RUN apt-get -y clean

# Copying needed files (dependencies)
COPY ./prerequisites/start-script.sh /start-script.sh
RUN chmod 777 /start-script.sh

# Create directory for mariadb-server socket
RUN mkdir /run/mysqld && chmod 777 /run/mysqld

# Expose only port 3306
EXPOSE 3306

# Healthcheck to check if mariadb is initialized and ready
HEALTHCHECK  --interval=10s --timeout=3s --retries=25 \
  CMD test -f /finished_init || exit 1

# Defaults that need to be set before starting mariadb
ENTRYPOINT [ "/start-script.sh" ]

# CMD for starting mariadb
CMD [ "mysqld" ]
