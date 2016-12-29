#!/usr/bin/perl

use Getopt::Std;
use Net::Jabber qw(Client);


getopts('t:');

my $timeout = $opt_t || 3;
my $verbose = 0;
require "/etc/skynet-client/skynet.conf";

my $recipient = shift;
my @message = @ARGV;


($recipient) = split(/\@/,$recipient);
$recipient .= "@" . "$server";


my $clnt = new Net::Jabber::Client;

my $status = $clnt->Connect(hostname=>$server, port=>$port, tls=>0);

if (!defined($status)) {
    die "Jabber connect error ($!)\n";
}

my @result = $clnt->AuthSend(username=>$username,
        password=>$password,
        resource=>$resource);

if ($result[0] ne "ok") {
    die "Jabber auth error: @result\n";
}


#$clnt->SetCallBacks(message=>&recvmsg, receive=>&recvmsg);
$clnt->SetMessageCallBacks(normal=>\&recvmsg, chat=>\&recvmsg);

$clnt->PresenceSend(type=>"available");

print "Sending: @message\n" if $verbose;
$clnt->MessageSend(to=>$recipient,
            subject=>"",
            body=>"@message",
            type=>"chat",
            priority=>10);


print "Waiting $timeout secs...\n" if $verbose;
sub recvmsg: {
	my ($sid,$msg) = @_;
	my $message = $msg->GetBody();
	print "Response: " if $verbose;
	print "$message\n";
	exit;
}


#sleep $timeout;
$clnt->WaitForID(1, $timeout);
#$clnt->Process(5);
print "End.\n" if $verbose;


$clnt->Disconnect();

