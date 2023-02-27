echo $LD_LIBRARY_PATH
if [[ "$0" = "$BASH_SOURCE" ]]; then
echo "[Error] : running in subshell, source script instead"
fi

if [ -z ${LD_LIBRARY_PATH} ]; then
    echo "setting environmental variable"
    export LD_LIBRARY_PATH="$(pwd)/../../lib/linux_x64d"
fi
