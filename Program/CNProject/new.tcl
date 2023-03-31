set val(stop)   40.0

set ns [new Simulator]

set tf [open new.tr w]
$ns trace-all $tf

set nf [open new.nam w]
$ns namtrace-all $nf

$ns color 1 Blue
$ns color 2 Red

for {set i 0} {$i<4} {incr i} {
set n($i) [$ns node]
}

$ns duplex-link $n(0) $n(2) 2Mb 10ms DropTail 
$ns duplex-link $n(1) $n(2) 2Mb 10ms DropTail 
$ns duplex-link $n(2) $n(3) 1.2Mb 20ms DropTail 
$ns duplex-link-op $n(0) $n(2) orient right-down 
$ns duplex-link-op $n(1) $n(2) orient right-up 
$ns duplex-link-op $n(2) $n(3) orient right
$ns duplex-link-op $n(2) $n(3) queuePos 0.5 

#define Agent
set tcp0 [new Agent/TCP]
$tcp0 set class_ 1
$ns attach-agent $n(0) $tcp0

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

set sink [new Agent/TCPSink]
$ns attach-agent $n(3) $sink
$ns connect $tcp0 $sink

set udp1 [new Agent/UDP]
$udp1 set class_ 2
$ns attach-agent $n(1) $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetSize_ 1000
$cbr1 set rate_ 1Mb
$cbr1 attach-agent $udp1

set null [new Agent/Null]
$ns attach-agent $n(3) $null
$ns connect $udp1 $null

set outfile [open new.txt w]
proc plotWindow {$tcp $outfile} {
	global ns
	set now [$ns now]
	set cwnd [$tcp set cwnd_]
puts $outfile "$now $cwnd"
$n at [expr $now+0.1] "plotWindow $tcp $outfile"
}

$ns at 1.0 "plotWindow $tcp0 $outfile"

#scheduling
proc finish {} {
	global ns nf tf
	$ns flush-trace
	close $nf
	close $tf
	exec nam new.nam &
	exit 0
}
$ns at 0.5 "$cbr1 start"
$ns at 1.0 "$ftp0 start"
$ns at 20 "$ftp0 stop"
$ns at 20.5 "$cbr1 stop"
$ns at 20.6 "finish"
$ns run
