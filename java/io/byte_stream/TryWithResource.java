import java.io.*;

class TryWithResource {
    public static void main(String args[]) throws IOException {
        try (FileInputStream fin = new FileInputStream("/etc/centos-release");
             FileOutputStream fout = new FileOutputStream("/tmp/centos-release")) {
            int i;
            do {
                i = fin.read();
                if(i != -1) fout.write(i);
            } while(i != -1);
        } 
        catch(IOException exc) {
            System.out.println("I/O Error: " + exc);
        }
    }
}
