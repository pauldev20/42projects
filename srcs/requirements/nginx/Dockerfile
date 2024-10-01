FROM debian:buster

# --------------------------------- METADATA --------------------------------- #
LABEL version="1.0"
LABEL description="NGINX Server"
LABEL author="pgeeser"

# ------------------------ UPDATE, UPGRADE AND INSTALL ----------------------- #
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install nginx openssl
RUN apt-get -y clean

# ----------------------- COPY DEPENDENCIES AND CONFIGS ---------------------- #
COPY ./prerequisites/start-script.sh /start-script.sh
RUN chmod 777 /start-script.sh
RUN rm -rf /etc/nginx/sites-enabled/default
COPY ./prerequisites/custom.conf /etc/nginx/sites-enabled/custom

# ------------------------------ PORT FORWARDING ----------------------------- #
EXPOSE 443

# Defaults that need to be set before starting nginx
ENTRYPOINT [ "/start-script.sh" ]

# CMD for starting nginx
CMD [ "nginx", "-g", "daemon off;" ]
