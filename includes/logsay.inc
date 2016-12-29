#!/usr/bin/perl
sub logsay: {
        my $message=shift;
        syslog("info","$message");
}
1;

