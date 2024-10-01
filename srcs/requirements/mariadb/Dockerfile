FROM debian:buster

# --------------------------------- METADATA --------------------------------- #
LABEL version="1.0"
LABEL description="MariaDB Server"
LABEL author="pgeeser"

# ------------------------ UPDATE, UPGRADE AND INSTALL ----------------------- #
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install mariadb-server
RUN apt-get -y clean

# ----------------------- COPY DEPENDENCIES AND CONFIGS ---------------------- #
COPY ./prerequisites/start-script.sh /start-script.sh
RUN chmod 777 /start-script.sh
COPY ./prerequisites/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# ------------------------------ PORT FORWARDING ----------------------------- #
EXPOSE 3306

# -------------------------------- HEALTHCHECK ------------------------------- #
HEALTHCHECK  --interval=10s --timeout=3s --retries=25 \
  CMD test -f /finished_init || exit 1

# Create directory for mariadb-server socket
RUN mkdir /run/mysqld && chmod 777 /run/mysqld

# Defaults that need to be set before starting mariadb
ENTRYPOINT [ "/start-script.sh" ]

# CMD for starting mariadb
CMD [ "mysqld" ]
