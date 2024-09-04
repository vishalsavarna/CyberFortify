#!/usr/bin/bash
sudo sysctl -w kernel.randomize_va_space=0
sudo ln -sf /bin/zsh /bin/sh


# For Task 4 you would have to use :
# sudo ln -sf /bin/bash /bin/sh

