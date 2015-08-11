import java.io.*;

class ReadFile2 {
    public static void main(String args[]) {
        FileInputStream fin = null;

        try {
            fin = new FileInputStream("/etc/centos-release");

            int i;
            do {
                i = fin.read();
                if(i != -1) System.out.print((char) i);
            } while(i != -1);

            fin.close();
        } catch(IOException e1) {
            System.out.println("Error when access file: " + e1);
        }
        finally {
            try {
                if (fin != null) fin.close();
            }
            catch(IOException e2) {
                System.out.println("Error when closing file.");
            }
        }
    }
}
