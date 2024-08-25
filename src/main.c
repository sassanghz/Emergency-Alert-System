//
// Created by sassa on 2024-08-23.
//
#include <stdio.h>
#include "contact.h"
#include "alert.h"

int main() {
    Contact contacts[100];
    int contact_count = 0;

    load_contacts_from_file(contacts, &contact_count, "data/contacts.txt");

    int choice;
    do {
        printf("\nEmergency Alert System\n");
        printf("1. Add Contact\n");
        printf("2. Edit Contact\n");
        printf("3. Remove Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Trigger Alert\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(contacts, &contact_count);
            break;
            case 2:
                edit_contact(contacts, contact_count);
            break;
            case 3:
                remove_contact(contacts, &contact_count);
            break;
            case 4:
                display_contacts(contacts, contact_count);
            break;
            case 5: {
                char message[256];
                printf("Enter alert message: ");
                scanf(" %[^\n]", message);  // Allows for spaces in input
                trigger_alert(message, contacts, contact_count);
                break;
            }
            case 6:
                save_contacts_to_file(contacts, contact_count, "data/contacts.txt");
            printf("Contacts saved. Exiting...\n");
            break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

