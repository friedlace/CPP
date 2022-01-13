#include "Paper.hpp"

Paper::Paper(int maxSymbols=4096) {
    this->maxSysmbols = maxSysmbols;
}

Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return this->maxSysmbols;
}

int Paper::getSymbols() const {
    return this->symbols;
}

void Paper::addContent(const std::string& message) {
    if ( this->maxSysmbols <= this->content.length() ) {
        throw OutOfSpaceException();
    }
    int available = this->maxSysmbols - this->content.length();
    if ( message.length() > available ) {
        this->content += message.substr(0, available);
        return;
    }
    this->content += message;
}

void Paper::show() const {
    return this->content;
}
