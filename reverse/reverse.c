#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header_buffer;
    fread(&header_buffer, sizeof(WAVHEADER), 1, infile);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header_buffer) == 0)
    {
        printf("Unsupported file format.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
        printf("Could not create %s.\n", argv[2]);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header_buffer, sizeof(WAVHEADER), 1, outfile);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header_buffer);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[block_size];
    for (fseek(infile, 0 - block_size, SEEK_END); ftell(infile) > sizeof(header_buffer) - block_size; fseek(infile, 0 - (block_size * 2), SEEK_CUR))
    {
        fread(buffer, block_size, 1, infile);
        fwrite(buffer, block_size, 1, outfile);
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
        return 1;

    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * header.bitsPerSample / 8;
}