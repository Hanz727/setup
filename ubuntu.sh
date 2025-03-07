#!/bin/bash
set -e

# Install essentials
sudo apt update && sudo apt upgrade -y && sudo apt install -y \
    clangd \
    python3.12 python3.12-dev python3.12-venv \
    npm \
    rustc cargo \
    python3-pip \
    build-essential \
    cmake \
    git \
    curl \
    wget \
    unzip \
    zsh \
    htop \
    tmux \
    tree \
    libclang-dev \
    libssl-dev \
    libz-dev \
    libsqlite3-dev \
    libjpeg-dev \
    libpng-dev \
    libgif-dev \
    libxml2-dev \
    libxslt1-dev \
    libffi-dev \
    python3-setuptools \
    python3-wheel \
    libpython3-dev \
    libncurses5-dev \
    libcurl4-openssl-dev \
    libbz2-dev \
    liblzma-dev \
    libreadline-dev \
    libsqlite3-dev \
    libyaml-dev \
    clang-format \
    clang-tidy \
    arduino \
    xsel

# Get nvim latest version
sudo add-apt-repository ppa:neovim-ppa/unstable -y
sudo apt update
sudo apt install -y neovim

# Install neovim config
git clone https://github.com/Hanz727/nvim-cfg.git ~/.config/nvim

# Install packer
git clone --depth 1 https://github.com/wbthomason/packer.nvim \
  ~/.local/share/nvim/site/pack/packer/start/packer.nvim
