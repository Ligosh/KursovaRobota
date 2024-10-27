#pragma once

namespace KursovaRobota {

    using namespace System;

    public ref class Book
    {
    private:
        String^ title;
        String^ author;
        int year;
        int quantity;

    public:
        Book(String^ title, String^ author, int year, int quantity)
        {
            this->title = title;
            this->author = author;
            this->year = year;
            this->quantity = quantity;
        }

        // Getters
        String^ getTitle() { return title; }
        String^ getAuthor() { return author; }
        int getYear() { return year; }
        int getQuantity() { return quantity; }

        // Setters
        void setQuantity(int newQuantity) { quantity = newQuantity; }
    };
}
