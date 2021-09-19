#!/bin/sh

echo "\033[36m                 _                         
                | |                        
  ___  ___  __ _| |__   ___  _ __ ___  ___ 
 / __|/ _ \\/ _\` | '_ \ / _ \\| '__/ __|/ _ \\
 \__ \  __/ (_| | | | | (_) | |  \__ \  __/
 |___/\___|\__,_|_| |_|\___/|_|  |___/\___| -- dev \n\033[0m"


sleep 1
echo "\033[32mbuilding seahorse project...\033[0m"

root_dir=$(dirname $(readlink -f "$0"))
build_dir="${root_dir}/output"

if [ -d "${build_dir}" ]; then
    rm -rf ${build_dir}
fi

if [ ! -d "${build_dir}" ]; then
    mkdir ${build_dir}
fi

if [ ! -x "$build_dir" ]; then
    echo " \033[31m$folder Permission denied\033[0m"
else
    cd $build_dir
    cmake .. \
            -DCMAKE_INSTALL_PREFIX="/usr/local"
    cmake_ret=$?
    if [ $cmake_ret -ne 0 ]; then
        echo "\033[31mrun cmake failed \033[0m"
        exit $cmake_ret
    else
        make
        make_ret=$?
        if [ $make_ret -ne 0 ]; then
            echo "\033[31mrun make failed\033[0m"
            exit $make_ret
        else
            sudo make install
            make_install_ret=$?
            if [ $make_install_ret -ne 0 ]; then
                echo "\033[31mrun make install failed\033[0m"
                exit $make_install_ret
            fi
        fi
    fi
fi 