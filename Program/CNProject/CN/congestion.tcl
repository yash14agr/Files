# This script is created by NSG2 beta1
# <http://wushoupong.googlepages.com/nsg>

#===================================
#     Simulation parameters setup
#===================================
set val(stop)   25.0                         ;# time of simulation end

#===================================
#        Initialization        
#===================================
#Create a ns simulator
set ns [new Simulator]

#Open the NS trace file
set tracefile [open congestion.tr w]
$ns trace-all $tracefile

#Open the NAM trace file
set namfile [open congestion.nam w]
$ns namtrace-all $namfile

#===================================
#        Nodes Definition        
#===================================
#Create 9 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]

#===================================
#        Links Definition        
#===================================
#Createlinks between nodes
$ns duplex-link $n0 $n1 100.0Mb 10ms DropTail
$ns queue-limit $n0 $n1 50
$ns duplex-link $n2 $n1 100.0Mb 10ms DropTail
$ns queue-limit $n2 $n1 50
$ns duplex-link $n3 $n1 100.0Mb 10ms DropTail
$ns queue-limit $n3 $n1 50
$ns duplex-link $n1 $n4 100.0Mb 10ms DropTail
$ns queue-limit $n1 $n4 50
$ns duplex-link $n5 $n1 100.0Mb 10ms DropTail
$ns queue-limit $n5 $n1 50
$ns duplex-link $n6 $n5 100.0Mb 10ms DropTail
$ns queue-limit $n6 $n5 50
$ns duplex-link $n8 $n6 100.0Mb 10ms DropTail
$ns queue-limit $n8 $n6 50
$ns duplex-link $n5 $n7 100.0Mb 10ms DropTail
$ns queue-limit $n5 $n7 50
$ns duplex-link $n5 $n8 100.0Mb 10ms DropTail
$ns queue-limit $n5 $n8 50
$ns duplex-link $n7 $n8 100.0Mb 10ms DropTail
$ns queue-limit $n7 $n8 50
$ns duplex-link $n3 $n6 100.0Mb 10ms DropTail
$ns queue-limit $n3 $n6 50
$ns duplex-link $n4 $n7 100.0Mb 10ms DropTail
$ns queue-limit $n4 $n7 50

#Give node position (for NAM)
$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n2 $n1 orient right-up
$ns duplex-link-op $n3 $n1 orient left-down
$ns duplex-link-op $n1 $n4 orient right-down
$ns duplex-link-op $n5 $n1 orient left

$ns duplex-link-op $n6 $n5 orient left-down
$ns duplex-link-op $n8 $n6 orient left-up
$ns duplex-link-op $n5 $n7 orient right-down
$ns duplex-link-op $n5 $n8 orient right
$ns duplex-link-op $n7 $n8 orient right-up
$ns duplex-link-op $n3 $n6 orient right
$ns duplex-link-op $n4 $n7 orient right

#===================================
#        Agents Definition        
#===================================
#Setup a TCP connection
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink5 [new Agent/TCPSink]
$ns attach-agent $n7 $sink5
$ns connect $tcp0 $sink5
$tcp0 set packetSize_ 1500

#Setup a TCP connection
set tcp1 [new Agent/TCP]
$ns attach-agent $n8 $tcp1
set sink4 [new Agent/TCPSink]
$ns attach-agent $n5 $sink4
$ns connect $tcp1 $sink4
$tcp1 set packetSize_ 1500

#Setup a TCP connection
set tcp3 [new Agent/TCP]
$ns attach-agent $n3 $tcp3
set sink2 [new Agent/TCPSink]
$ns attach-agent $n5 $sink2
$ns connect $tcp3 $sink2
$tcp3 set packetSize_ 1500


#===================================
#        Applications Definition        
#===================================
#Setup a FTP Application over TCP connection
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ns at 1.0 "$ftp0 start"
$ns at 2.0 "$ftp0 stop"

#Setup a FTP Application over TCP connection
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp3
$ns at 1.0 "$ftp1 start"
$ns at 2.0 "$ftp1 stop"

#Setup a FTP Application over TCP connection
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp1
$ns at 1.0 "$ftp2 start"
$ns at 2.0 "$ftp2 stop"

proc plotWindow {tcpSource filename} {
 	global ns
	set now [$ns now]
	set cwnd [$tcpSource set cwnd_]
puts $filename "$now $cwnd"
$ns at [expr $now+0.1] "plotWindow $tcpSource $filename"
}
set outfile [open "tcp0.plot" w]
$ns at 0.0 "plotWindow $tcp0 $outfile"

set outfile1 [open "tcp1.plot" w]
$ns at 0.0 "plotWindow $tcp1 $outfile1"

set outfile2 [open "tcp3.plot" w]
$ns at 0.0 "plotWindow $tcp3 $outfile2"

#===================================
#        Termination        
#===================================
#Define a 'finish' procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam congestion.nam &
    exit 0
}
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run
