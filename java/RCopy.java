import java.io.*;
import java.lang.*;
import java.util.*;

public class RCopy
{
    public static void main (String[] args) {
        try {
            RandomAccessFile inFile = new RandomAccessFile(args[0], "r");
            FileOutputStream outStream = new FileOutputStream(args[1]);

            for(long p = inFile.length() - 1; p >= 0; p--) {
                inFile.seek(p);
                int b = inFile.read();
                outStream.write(b);
            }

            inFile.close ();
            outStream.close ();
        } catch (IOException e) {
            System.out.println ("IO-Exception while: " + e.toString());
        }

    }
}