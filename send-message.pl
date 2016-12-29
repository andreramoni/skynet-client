#!/usr/bin/perl

use Net::Jabber qw(Client);

require "/etc/skynet-client/skynet.conf";

my $recipient = shift;
my @message = @ARGV;


($recipient) = split(/\@/,$recipient);
$recipient .= "@" . "$server";
print "$recipient\n";


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


$clnt->MessageSend(to=>$recipient,
            subject=>"",
            body=>"@message",
            type=>"chat",
            priority=>10);

$clnt->Disconnect();

