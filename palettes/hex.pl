#!/usr/bin/env perl
use warnings;
use strict;

system("clear");

my @palettes = `ls *.palette`;
chomp @palettes;

foreach my $pal_file (@palettes)
{
    my @tokens = split /\./, $pal_file;
    my $hex_file = $tokens[0] . ".hex";

    open FIN, $pal_file;
    open FOUT, ">$hex_file";

    while(<FIN>)
    {
        my $line = $_;
        chomp $line;
        my @strings = split / /, $line;
        my $hex_value = $strings[1];

        print FOUT "$hex_value\n";
    }

    close FOUT;
    close FIN;
}
