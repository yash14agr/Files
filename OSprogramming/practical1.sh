ls
cd /
lscpu
cd /proc
cat cpuinfo
cat cpuinfo | grep -h processor
cat cpuinfo | grep -h core
cat cpuinfo | grep -h MHz
cat meminfo | grep -h processes
cat stat | grep -h ctxt


