//
// Created by sassa on 2024-08-23.
//

#ifndef CONTACT_H
#define CONTACT_H


#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact(Contact contacts[], int *contact_count);
void edit_contact(Contact contacts[], int contact_count);
void remove_contact(Contact contacts[], int *contact_count);
void display_contacts(Contact contacts[], int *contact_count);
void save_contacts_to_file(Contact contacts[], int contact_count, const char *filename);
void load_contacts_from_file(Contact contacts[], int *contact_count, const char *filename);

#endif
