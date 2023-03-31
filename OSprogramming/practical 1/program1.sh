cd /
cd proc
echo "Number of Processors:"
cat cpuinfo | grep processor
echo
echo "Number of Cores:"
cat cpuinfo | grep cores
echo
echo "Frequency of each processor:"
cat cpuinfo | grep MHz
echo
echo "Physical Memory in system:"
cat meminfo | grep MemTotal
echo
echo "Free Memory in system:"
cat meminfo | grep MemFree
echo
echo "Number of Forks since boot in the system:"
cat stat | grep processes
echo
echo "Number of Context Switches since boot in the system:"
cat stat | grep ctxt

