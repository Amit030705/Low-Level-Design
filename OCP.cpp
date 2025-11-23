#include <iostream>
#include <string>
using namespace std;

// User model
class User {
private:
    string doc;

public:
    User(string doc) {
        this->doc = doc;
    }
};

// Interface (abstraction)
class IGenerate {
public:
    virtual void generate() = 0;
    virtual ~IGenerate() = default;
};

// Concrete implementations
class Pdf : public IGenerate {
public:
    void generate() override {
        cout << "📄 Generating PDF Document\n";
    }
};

class Excel : public IGenerate {
public:
    void generate() override {
        cout << "📊 Generating Excel Document\n";
    }
};

// Client class using abstraction (OCP)
class DocumentService {
private:
    IGenerate* generator;

public:
    DocumentService(IGenerate* generator) {
        this->generator = generator;
    }

    void createDocument() {
        generator->generate();
    }
};

int main() {
    Pdf pdfFormat;
    Excel excelFormat;

    DocumentService pdfDoc(&pdfFormat);
    DocumentService excelDoc(&excelFormat);

    pdfDoc.createDocument();
    excelDoc.createDocument();

    return 0;
}
