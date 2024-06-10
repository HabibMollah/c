#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Validate user input
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open memory card file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Create buffer to store 512 bytes
    BYTE buffer[BLOCK_SIZE];

    // Create a counter to keep track of the number of images found
    int image_counter = 0;

    // Create a file pointer to store the image file
    FILE *img = NULL;

    // Create a flag to check if the first JPEG is found
    int first_jpeg = 0;

    // Read the file until the end
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check if the first 4 bytes of the buffer are the start of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If the first JPEG is found, close the previous image file
            if (first_jpeg == 1)
            {
                fclose(img);
            }
            else
            {
                first_jpeg = 1;
            }

            // Create a filename for the image
            char filename[8];
            sprintf(filename, "%03i.jpg", image_counter);

            // Open the image file
            img = fopen(filename, "w");
            if (img == NULL)
            {
                return 1;
            }

            // Write the buffer to the image file
            fwrite(buffer, BLOCK_SIZE, 1, img);

            // Increment the image counter
            image_counter++;
        }
        else
        {
            // If the first JPEG is found, write the buffer to the image file
            if (first_jpeg == 1)
            {
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
        }
    }

    // Close the last image file
    fclose(img);

    // Close the memory card file
    fclose(file);

    return 0;
}