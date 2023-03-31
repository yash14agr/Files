#Step-1: Initializing the network:

set ns [new Simulator]
$ns rtproto LS

#Step-2: Creating number of nodes:

set node1 [$ns node]
set node2 [$ns node]
set node3 [$ns node]
set node4 [$ns node]

set node5 [$ns node]
set node6 [$ns node]
set node7 [$ns node]

#Step-3: Creating the trace file:

set tf [open out.tr w]
$ns trace-all $tf
set nf [open out.nam w]
$ns namtrace-all $nf

#Step-4: Labeling the nodes:

$node1 label "node 1"
$node1 label "node 2"
$node1 label "node 3"
$node1 label "node 4"
$node1 label "node 5"
$node1 label "node 6"
$node1 label "node 7"
$node1 label-color blue
$node2 label-color red
$node3 label-color red
$node4 label-color blue
$node5 label-color blue
$node6 label-color blue
$node7 label-color blue

#Step-5: Creating duplex links:

$ns duplex-link $node1 $node2 1.5Mb 10ms DropTail
$ns duplex-link $node2 $node3 1.5Mb 10ms DropTail

$ns duplex-link $node3 $node4 1.5Mb 10ms DropTail
$ns duplex-link $node4 $node5 1.5Mb 10ms DropTail
$ns duplex-link $node5 $node6 1.5Mb 10ms DropTail
$ns duplex-link $node6 $node7 1.5Mb 10ms DropTail
$ns duplex-link $node7 $node1 1.5Mb 10ms DropTail

#Step-6: Orient the links between the nodes:

$ns duplex-link-op $node1 $node2 orient left-down
$ns duplex-link-op $node2 $node3 orient left-down
$ns duplex-link-op $node3 $node4 orient right-down
$ns duplex-link-op $node4 $node5 orient right
$ns duplex-link-op $node5 $node6 orient right-up
$ns duplex-link-op $node6 $node7 orient left-up
$ns duplex-link-op $node7 $node1 orient left-up

#Step-7: Attaching TCP agents:

set tcp2 [new Agent/TCP]
$ns attach-agent $node1 $tcp2
set sink2 [new Agent/TCPSink]
$ns attach-agent $node4 $sink2
$ns connect $tcp2 $sink2

#Step-8: Creating FTP traffic:

set traffic_ftp2 [new Application/FTP]
$traffic_ftp2 attach-agent $tcp2
$traffic_ftp2 set type_ FTP


#Step-9: Adding a finish procedure:

proc finish {} {
    global ns nf
    $ns flush-trace
    #Close the NAM trace file
    close $nf
    #Execute NAM on the trace file
    exec nam out.nam &
    exit 0
}

#Step-10: Scheduling the FTP:

$ns at 0.5 "$traffic_ftp2 start"
$ns rtmodel-at 1.0 down $node2 $node3
$ns rtmodel-at 2.0 up $node2 $node3
$ns at 3.0 "$traffic_ftp2 start"
$ns at 4.0 "$traffic_ftp2 stop"
$ns at 5.0 "finish"
$ns run
