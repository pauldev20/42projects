FROM debian:buster

# Metadata
LABEL version="1.0"
LABEL description="NGINX Server"
LABEL author="pgeeser"

# Update and upgrade
RUN apt-get -y update
RUN apt-get -y upgrade

# Install nginx
RUN apt-get -y install nginx openssl

# Clean up
RUN apt-get -y clean

# Copying needed files (prerequisites)
COPY ./prerequisites/start-script.sh /start-script.sh
RUN chmod 777 /start-script.sh
RUN rm -rf /etc/nginx/sites-enabled/default
COPY ./prerequisites/custom.conf /etc/nginx/sites-enabled/custom

# Expose only port 443
EXPOSE 443

# Defaults that need to be set before starting nginx
ENTRYPOINT [ "/start-script.sh" ]

# CMD for starting nginx
CMD [ "nginx", "-g", "daemon off;" ]
