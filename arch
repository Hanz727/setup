#!/bin/bash
set -e

# Install essentials using pacman
sudo pacman -Syu --noconfirm
sudo pacman -S --noconfirm \
    clang \
    python python-dev python-virtualenv \
    npm \
    rust \
    python-pip \
    base-devel \
    cmake \
    git \
    curl \
    wget \
    unzip \
    zsh \
    htop \
    tmux \
    tree \
    llvm \
    openssl \
    zlib \
    sqlite \
    libjpeg \
    libpng \
    giflib \
    libxml2 \
    libxslt \
    libffi \
    python-setuptools \
    python-wheel \
    ncurses \
    libcurl \
    bzip2 \
    xsel

# Get the latest version of Neovim from the official repos
sudo pacman -S --noconfirm neovim

# Ensure the directory exists before cloning
NVIM_CONFIG_PATH="$HOME/.config/nvim"

if [ ! -d "$NVIM_CONFIG_PATH" ]; then
  echo "Installing Neovim config..."
  git clone https://github.com/Hanz727/nvim-cfg.git "$NVIM_CONFIG_PATH" || {
    echo "Failed to clone Neovim config" >&2
    exit 1
  }
else
  echo "Neovim config is already installed."
fi

# Ensure the directory exists before cloning packer.nvim
PACKER_PATH="$HOME/.local/share/nvim/site/pack/packer/start/packer.nvim"
if [ ! -d "$PACKER_PATH" ]; then
  echo "Installing packer.nvim..."
  git clone --depth 1 https://github.com/wbthomason/packer.nvim "$PACKER_PATH" || {
    echo "Failed to clone packer.nvim" >&2
    exit 1
  }
else
  echo "packer.nvim is already installed."
fi

### 1. Enable Case-Insensitive Tab Completion for `cd`
INPUTRC="$HOME/.inputrc"
if ! grep -q "completion-ignore-case" "$INPUTRC" 2>/dev/null; then
    echo -e "\n# Enable case-insensitive tab completion" >> "$INPUTRC"
    echo "set completion-ignore-case on" >> "$INPUTRC"
    echo "set show-all-if-ambiguous on" >> "$INPUTRC"
    echo "Case-insensitive tab completion enabled."
else
    echo "Case-insensitive tab completion is already enabled."
fi

### 2. Set Faster Keyboard Repeat Rate
if ! grep -q "xset r rate" "$HOME/.bashrc"; then
    echo -e "\n# Set faster keyboard repeat rate" >> "$HOME/.bashrc"
    echo "xset r rate 200 50" >> "$HOME/.bashrc"
    echo "Keyboard repeat rate set to 200ms delay, 50 repeats/sec."
else
    echo "Keyboard repeat rate is already configured."
fi

TMUX_CONF="$HOME/.tmux.conf"

# Check if the tmux.conf file exists
if [ ! -f "$TMUX_CONF" ]; then
  # Create the tmux.conf file and write the settings to it
  cat > "$TMUX_CONF" <<EOL
set -g default-terminal "tmux-256color"
set -s escape-time 0
set -g base-index 1

# optional -- i like C-a not C-b (pure preference)
unbind C-b
set-option -g prefix C-a
bind-key C-a send-prefix

# vi key movement for copy/paste mode
set-window-option -g mode-keys vi
bind -T copy-mode-vi v send-keys -X begin-selection
bind -T copy-mode-vi y send-keys -X copy-pipe-and-cancel 'xclip -in -selection clipboard'

bind -r h select-pane -L
bind -r j select-pane -D
bind -r k select-pane -U
bind -r l select-pane -R

bind r source-file ~/.tmux.conf \; display-message "tmux.conf reloaded"
EOL
  echo ".tmux.conf created at $TMUX_CONF"
else
  echo ".tmux.conf already exists at $TMUX_CONF"
fi

# Apply changes
exec bash
