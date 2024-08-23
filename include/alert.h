//
// Created by sassa on 2024-08-23.
//
// This header function declares the functions and data structures that will be used across different modules.


#ifndef ALERT_H
#define ALERT_H

#include "contact.h"

void trigger_alert(const char *message, Contact contacts[], int contact_count);
void send_email(const char *recipient_email, const char *subject, const char *message_body);

// Add a function for sending an SMS
#endif //ALERT_H
