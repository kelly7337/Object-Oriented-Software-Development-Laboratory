#include <iostream>
#include <iomanip>
#include "MetadataDisplayVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"


using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
	cout << left << setw(20) << file->getName() << "\ttext\t" << setw(5) << file->getSize() << endl;

}
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	cout << left << setw(20) << file->getName() << "\timage\t" << setw(5) << file->getSize() << endl;
}