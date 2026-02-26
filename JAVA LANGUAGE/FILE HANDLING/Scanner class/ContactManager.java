import java.io.*;
import java.util.*;
public class ContactManager {
    private static final String FILE_NAME="contacts.txt";
    private static Scanner scanner=new Scanner(System.in);
    public static void main(String[] args) {
        while(true) {
            System.out.println("\n=== CONTACT MANAGER ===");
            System.out.println("1. Add 5 contacts");
            System.out.println("2. Search for a contact");
            System.out.println("3. Delete a contact");
            System.out.println("4. Display all contacts");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice=scanner.nextInt();
            scanner.nextLine(); 
            switch (choice) {
                case 1:
                    addContacts();
                    break;
                case 2:
                    searchContact();
                    break;
                case 3:
                    deleteContact();
                    break;
                case 4:
                    displayAllContacts();
                    break;
                case 5:
                    System.out.println("Goodbye!");
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }
    public static void addContacts() {
        try(FileWriter writer = new FileWriter(FILE_NAME)) {
            for(int i = 1; i <= 5; i++) {
                System.out.println("\nEnter details for contact " + i + ":");
                System.out.print("Enter name: ");
                String name = scanner.nextLine();
                System.out.print("Enter mobile number: ");
                String mobile = scanner.nextLine();
                writer.write(name + "," + mobile + "\n");
            }
            System.out.println("\n5 contacts saved successfully to " + FILE_NAME);
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }
    public static void searchContact() {
        System.out.print("\nEnter name to search: ");
        String searchName = scanner.nextLine();
        boolean found=false;
        try(BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    String name = parts[0].trim();
                    String mobile = parts[1].trim();
                    
                    if (name.equalsIgnoreCase(searchName)) {
                        System.out.println("\nContact found:");
                        System.out.println("Name: " + name);
                        System.out.println("Mobile: " + mobile);
                        found = true;
                        break;
                    }
                }
            }
            if(!found) {
                System.out.println("Contact '" + searchName + "' not found.");
            }
        } catch (FileNotFoundException e) {
            System.out.println("No contacts file found. Please add contacts first.");
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
    public static void deleteContact() {
        System.out.print("\nEnter name to delete: ");
        String deleteName = scanner.nextLine();
        File inputFile = new File(FILE_NAME);
        File tempFile = new File("temp_contacts.txt");
        
        boolean found = false;
        try(BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            FileWriter writer = new FileWriter(tempFile)) {
            String line;
            while((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    String name = parts[0].trim();
                    if(name.equalsIgnoreCase(deleteName)) {
                        found = true;
                        continue; // Skip writing this contact
                    }
                    writer.write(line + "\n");
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("No contacts file found. Please add contacts first.");
            return;
        } catch (IOException e) {
            System.out.println("Error processing file: " + e.getMessage());
            return;
        }
        if(found) {
            if (inputFile.delete()) {
                if (tempFile.renameTo(inputFile)) {
                    System.out.println("Contact '" + deleteName + "' deleted successfully.");
                } else {
                    System.out.println("Error renaming temp file.");
                }
            } else {
                System.out.println("Error deleting original file.");
            }
        } else {
            tempFile.delete(); // Clean up temp file
            System.out.println("Contact '" + deleteName + "' not found.");
        }
    }
    public static void displayAllContacts() {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            System.out.println("\n=== ALL CONTACTS ===");
            String line;
            int count = 0;
            while((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    count++;
                    System.out.println(count + ". " + parts[0].trim() + " - " + parts[1].trim());
                }
            }
            if(count == 0) {
                System.out.println("No contacts found.");
            }
        } catch (FileNotFoundException e) {
            System.out.println("No contacts file found. Please add contacts first.");
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}