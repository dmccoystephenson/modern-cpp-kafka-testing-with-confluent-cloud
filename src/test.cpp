// using this as a reference https://github.com/morganstanley/modern-cpp-kafka/blob/main/examples/kafka_sync_producer.cc

#include <string>
#include <iostream>
#include "kafka/KafkaProducer.h"

using namespace std;

void log(string message) {
    cout << "[LOG] " << message << endl;
}

const char* getEnvironmentVariable(const char* variableName) {
    const char* toReturn = getenv(variableName);
    if (!toReturn) {
        cout << "[ERROR] Something went wrong attempting to retrieve the environment variable " << variableName << endl;
    }
    return toReturn;
}

int main() {
    log("Executing program.");

    string brokers = "";
    string topic = "";
    string message = "";

    try {
        // create config object
        kafka::Properties properties({
            {"bootstrap.servers", brokers}
            {"enable.idempotence", "true"}
        })

        // create producer
        KafkaProducer producers(properties):

        // prepare record
        auto record = producer::ProducerRecord(topic, kafka::NullKey, Kafka::Value(message.c_str(), message.size());

        // send message
        try {
            producer::RecordMetaData metadata = producer.syncSend(record);
            log("Message delivered.");

        } catch(const kafka::KafkaException& e) {
            cout << "[ERROR] Message delivery failed: " << e.error().message() << endl;
        }


    } catch(kafka::KafkaException& e) {
        cout << "[ERROR] Unexpected exception: " << e.what() << endl;
    }

    log("Finished executing program.");
    return 0;
}