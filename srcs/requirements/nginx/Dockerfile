FROM debian:buster

# Update and upgrade
RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y clean

# Install nginx
RUN apt-get -y install nginx
RUN apt-get -y clean

# Copying needed files (prerequisites)
COPY /prerequisites/start-script.sh /start-script.sh

# Starting "command"
ENTRYPOINT [ "/start-script.sh" ]

# Defaluts for starting container (starting nginx)
CMD [ "" ]
