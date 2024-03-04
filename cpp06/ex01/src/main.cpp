/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 02:34:52 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/03 23:14:42 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"
#include <iostream>

int main() {
    // Create originalData with different values
    Data* originalData = new Data(42);

	std::cout << std::endl;
	std::cout << "========== SERIALIZE ORIGINAL DATA ==========" << std::endl;
    uintptr_t serializedPtr = Serializer::serialize(originalData);
    std::cout << "Serialization Data value: " << serializedPtr << std::endl;
	std::cout << std::endl;

	std::cout << "========== DESERIALIZE THE POINTER ==========" << std::endl;
    Data* deserializedData = Serializer::deserialize(serializedPtr);
    std::cout << "Deserialization Data value: " << deserializedData << std::endl;
	std::cout << std::endl;
	
	std::cout << "=== CHECK EQUALITY AFTER DESERIALIZATION ===" << std::endl;
    if (deserializedData == originalData) {
        std::cout << "Serialization and deserialization successful." << std::endl;
        std::cout << "Original Data value: " << originalData->getDataValue() << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed." << std::endl;
    }
	std::cout << std::endl;

	std::cout << "======== CHECK IF THE VALUES MATCH ========" << std::endl;
    if (deserializedData->getDataValue() == originalData->getDataValue()) {
        std::cout << "Data values match after deserialization." << std::endl;
    } else {
        std::cout << "Data values do not match after deserialization." << std::endl;
    }
	std::cout << std::endl;

	std::cout << "==== CHECK FOR A DIFFERENT DATA OBJECT ====" << std::endl;
    Data* newData = new Data(99);
    uintptr_t newSerializedPtr = Serializer::serialize(newData);
    Data* newDeserializedData = Serializer::deserialize(newSerializedPtr);

    if (newDeserializedData->getDataValue() == newData->getDataValue()) {
        std::cout << "Serialization and deserialization for a different Data object successful." << std::endl;
        std::cout << "New Data value: " << newData->getDataValue() << std::endl;
    } else {
        std::cout << "Serialization and deserialization for a different Data object failed." << std::endl;
    }
	std::cout << std::endl;

    delete originalData;
    delete newData;

    return (0);
}
