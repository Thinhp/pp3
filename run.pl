#!/usr/bin/env perl
use warnings;
use strict;

my $jobid;
my $arg;
my $filename;
my $outputDir = "output/";

if (@ARGV == 0) { &usage; }

$arg = shift;

if ($arg eq "-h")
{
    &usage;
}
elsif ($arg eq "-t")
{
    $arg = shift;
    if ($arg eq "")
    { $arg = "Painter.txt"; }
    $filename = &computeFilename();
    $jobid = &computeTimestamp();
    $outputDir .= $filename . "_" . $jobid;
    &executeRun;
}
elsif ($arg eq "-j")
{
	$arg = shift;
    $filename = &computeFilename();
    my @tokens =  split(/\./, $ENV{'PBS_JOBID'});
    $outputDir .= $tokens[0] . "_" . $filename;
    print "\n" . $outputDir  . "\n";
    &executeRun;
}
elsif ($arg eq "-o")
{
    $arg = shift;
    if ($arg eq "")
    {
        &usage;
    }
    else
    {
        $jobid = $arg;
        $outputDir .= $jobid;
        &executeRun;
    }
}
else
{
    &usage;
}

sub usage
{
    system("clear");
    print "\nDESCRIPTION\n";
    print "Performs an evolutionary run using the parameters specified in ";
    print "the Painter.txt\nfile.\n\n";
    print "PARAMETERS:\n";
    print "\t-t:\tThe application determines the name of the output folder ";
    print "based\n\ton the target specified in Painter.txt and the current time\n";
    print "\t-j:\tThe application determines the name of the output folder ";
    print "based\n\ton the target specified in Painter.txt and the VPAC job number\n";
    print "\n\t-o <jobid>:\tThe output folder is named the jobid specified\n\n";
    exit;
}

sub computeFilename
{
    my $ret;

    open (CONFIG, "$arg");
    while (<CONFIG>)
    {
        next if $_ !~ /targetFilename/;
        chomp;
        my @tokens = split(" ", $_);
        $ret = $tokens[1];
    }
    close CONFIG;

    return $ret;
}

sub computeTimestamp
{
    open FH, "date +%y%m%d%H%M |";
    my $date = <FH>;
    chomp $date;
    close FH;

    my $y = substr($date, 0, 2);
    my $m = substr($date, 2, 2);
    my $d = substr($date, 4, 2);
    my $h = substr($date, 6, 6);
    my $s = substr($date, 8, 6);
    my $ret = "$y-$m-$d-$h-$s";

    return $ret
}

sub executeRun
{
    system("mkdir $outputDir");
    system("mkdir $outputDir/pgm");
    system("mkdir $outputDir/png");
    system("cp $arg $outputDir");
    system("./NPR-GP $outputDir $arg");
    system("mv $outputDir/png/best.png $outputDir");
    system("mv $outputDir/pgm/best.pgm $outputDir");
    print "Movie will be created in $outputDir\n";
    system("bash create_movies2.sh $outputDir");
}

