# Use an official Python runtime as a parent image
FROM python:3.9-slim-buster

# Set the working directory to /app
WORKDIR /app

# Copy the code files into the container
COPY . .

# Install the required packages
RUN apt-get update && apt-get install -y arduino-mk

# Compile the sketch
RUN make

# Define the command to run when the container starts
CMD ["./upload.sh"]
