import java.io.*;
class CopyFile {
    public static void main(String args[]) throws IOException {
        FileInputStream fin = null;
        FileOutputStream fout = null;

        try {
            fin = new FileInputStream("/etc/centos-release");
            fout = new FileOutputStream("/tmp/centos-release");

            int i;
            do {
                i = fin.read();
                if(i != -1) fout.write(i);
            } while(i != -1);
        } 
        catch(IOException exc) {
            System.out.println("I/O Error: " + exc);
        } 
        finally {
            try {
                if(fin != null) fin.close();
            } 
            catch(IOException exc) {
                System.out.println("Error Closing Input File");
            }

            try {
                if(fout != null) fout.close();
            } 
            catch(IOException exc) {
                System.out.println("Error Closing Output File");
            }
        }
    }
}
