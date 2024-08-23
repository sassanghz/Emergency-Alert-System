//
// Created by sassa on 2024-08-23.
//
// The following source files contain the implementation of the functions declared in the header files

#include <stdio.h>
#include <string.h>
#include "contact.h"

void add_contact(Contact contacts[], int *contact_count) {
    if(*contact_count >= 100) {
        printf(("Contact list is full!\n"));
        return;
    }

    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter email: ");
    scanf("%s", new_contact.email);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);

    contacts[*contact_count] = new_contact;
    (*contact_count)++;
    printf("Contact added successfully!\n");
}

void edit_contact(Contact contacts[], int contact_count) {

}

void remove_contact(Contact contacts[], int *contact_count) {
    // Implementation as discussed earlier.
}

void display_contacts(Contact contacts[], int contact_count) {
    // Implementation as discussed earlier.
}

void save_contacts_to_file(Contact contacts[], int contact_count, const char *filename) {
    // Implementation as discussed earlier.
}

void load_contacts_from_file(Contact contacts[], int *contact_count, const char *filename) {
    // Implementation as discussed earlier.
}



