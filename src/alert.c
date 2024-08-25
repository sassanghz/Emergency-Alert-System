//
// Created by sassa on 2024-08-23.
//
#include <stdio.h>
#include "alert.h"
#include <curl/curl.h>

void trigger_alert(const char *message, Contact contacts[], int contact_count) {
    printf("Triggering alert: %s\n", message);
    for (int i = 0; i < contact_count; i++) {
        send_email(contacts[i].email, "Emergency Alert", message);
        // Call send_sms if implemented
    }
}

void send_email(const char *recipient_email, const char *subject, const char *message_body) {
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, "your_email@gmail.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password");
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "your_email@gmail.com");

        recipients = curl_slist_append(recipients, recipient_email);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        char payload_text[500];
        snprintf(payload_text, sizeof(payload_text),
                 "To: %s\r\n"
                 "From: your_email@gmail.com\r\n"
                 "Subject: %s\r\n\r\n"
                 "%s", recipient_email, subject, message_body);
        curl_easy_setopt(curl, CURLOPT_READDATA, payload_text);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        res = curl_easy_perform(curl); // preform the request
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_slist_free_all(recipients); // clears the memory
        curl_easy_cleanup(curl);
    }
}
