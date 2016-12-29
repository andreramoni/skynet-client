#!/usr/bin/perl

my $tmpfile="/tmp/ncheck.tmp.$$";
my $number=0;
my $nagios_user='';
my $nagios_passwd='';
my $arg = shift;


my %hostgroup_hash = (
  "exchange" => "Ambiente-Exchange",
  "linux"    => "Tecnologia-Linux",
  "dns"    => "Ambiente-DNS",
  "storage"    => "Ambiente-Storage",
  "gerenciamento"    => "Ambiente-Gerenciamento",
  "cloud"    => "Ambiente-Cloud",
);


my $hostgroup = $hostgroup_hash{$arg};

my $deschg = $hostgroup || "Geral";

if($hostgroup) {
	system("/usr/bin/wget --http-user $nagios_user --http-password $nagios_passwd  'http://nagios/nagios3/cgi-bin/status.cgi?hostgroup=$hostgroup&style=detail' -O $tmpfile 2> /dev/null > /dev/null");
} else {
	system("/usr/bin/wget --http-user $nagios_user --http-password $nagios_passwd  'http://nagios/nagios3/cgi-bin/status.cgi?' -O $tmpfile 2> /dev/null > /dev/null");
}

open(FH, $tmpfile);

while(<FH>){
	if($_ =~ /CLASS='statusBGWARNING'><A HREF='extinfo.cgi\?type=2&host=(.*)\&service=.*'>(.*)<\/A/i) {
		next if ( "$2" =~ /Check Hostgroup/);
		next if ( "$2" =~ /Uptime/);
		$hash{$1}{$2}++ ; 
		$number++;
	}
	if($_ =~ /CLASS='statusBGCRITICAL'><A HREF='extinfo.cgi\?type=2&host=(.*)\&service=.*'>(.*)<\/A/i) {
		next if ( "$2" =~ /Check Hostgroup/);
		next if ( "$2" =~ /(TIME|Uptime)/);
		$hash{$1}{$2}++ ; 
		$number++;
	}
	#elsif($_ =~ /itemTotalsTitle.*\>0 Matching Service/) { print "0 Matching Service Entries Displayed\n" ; exit 1 }

}
close(FH);
unlink($tmpfile);

if ($number eq 0){
	#print "nenhum problema com o hostgroup $hostgroup\n";
  print "($deschg) nenhum problema\n";
	exit 0;
}

# Else deu problema:
my $msg="";
foreach(keys(%hash)){
        my $host = $_;
        $msg .= "$host(";
        foreach(keys(%{@hash{$_}})){ $msg .= "$_, " }
        $msg .=  "); ";
}


# bypass:
#print "nenhum problema\n";
#exit 0;


print "($deschg) $number problemas: $msg";




#foreach(keys(%hash)){
#	my $host = $_;
#	print "$host(";
#	foreach(keys(%{@hash{$_}})){ print "$_, " }
#	print "); ";
#}
print "\n";

exit 1;
