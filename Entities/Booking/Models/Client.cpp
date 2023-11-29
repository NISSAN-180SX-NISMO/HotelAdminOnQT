//
// Created by user on 28.11.2023.
//

#include "Client.h"
int Client::ID = 0;

Client *Client::clientFromJSON(nlohmann::json client_data) {
    return new Client(QString::fromStdString(client_data["name"]));
}