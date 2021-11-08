#include "pch.h"
#include <fstream>
#include <PCBD.h>
TEST(Contact,DefaultConstructor)
{
	Contact contact;
	EXPECT_EQ(contact.type, 0);
	EXPECT_EQ(contact.x, 0);
	EXPECT_EQ(contact.y, 0);
	EXPECT_EQ(contact.connected_num, -1);
}
TEST(Contact, Constructor)
{
	Contact contact = Contact(OUTPUT, 2, 8);
	EXPECT_EQ(contact.type, OUTPUT);
	EXPECT_EQ(contact.x, 2);
	EXPECT_EQ(contact.y, 8);
	EXPECT_EQ(contact.connected_num, -1);

	contact = Contact(OUTPUT, 3, 2);
	EXPECT_EQ(contact.type, OUTPUT);
	EXPECT_EQ(contact.x, 3);
	EXPECT_EQ(contact.y, 2);
	EXPECT_EQ(contact.connected_num, -1);
}
TEST(Contact, EqualityOverload)
{
	EXPECT_TRUE(Contact(INPUT, 2, 8) == Contact(INPUT, 2, 8));
	EXPECT_TRUE(Contact(OUTPUT, 1, 2) == Contact(INPUT, 1, 2));
	EXPECT_FALSE(Contact(INPUT, 2, 2) == Contact(INPUT, 2, 5));
	EXPECT_FALSE(Contact(INPUT, 1, 6) == Contact(OUTPUT, 3, 0));
}
TEST(PCB, CopyAssignment)
{
	PCB pcb1 = PCB(INPUT, 2, 3);
	pcb1.add_contact(INPUT, 2, 4);
	pcb1.add_contact(OUTPUT, 1, 3);
	PCB pcb2 = pcb1;
	Contact* trass = new Contact[3];
	pcb2.get_Contacts(trass);
	EXPECT_EQ(trass[0].type, INPUT);
	EXPECT_EQ(trass[0].x, 2);
	EXPECT_EQ(trass[0].y, 3);
	EXPECT_EQ(trass[0].connected_num, -1);

	EXPECT_EQ(trass[1].type, INPUT);
	EXPECT_EQ(trass[1].x, 2);
	EXPECT_EQ(trass[1].y, 4);
	EXPECT_EQ(trass[1].connected_num, -1);

	EXPECT_EQ(trass[2].type, OUTPUT);
	EXPECT_EQ(trass[2].x, 1);
	EXPECT_EQ(trass[2].y, 3);
	EXPECT_EQ(trass[2].connected_num, -1);
	delete[] trass;
}
TEST(PCB, MoveAssignment)
{
	PCB pcb1 = PCB(OUTPUT, 5, 3);
	pcb1.add_contact(INPUT, 2, 2);
	pcb1.add_contact(INPUT, 2, 3);
	PCB pcb2 = move(pcb1);
	Contact* trass = new Contact[3];
	pcb2.get_Contacts(trass);
	EXPECT_EQ(trass[0].type, OUTPUT);
	EXPECT_EQ(trass[0].x, 5);
	EXPECT_EQ(trass[0].y, 3);
	EXPECT_EQ(trass[0].connected_num, -1);

	EXPECT_EQ(trass[1].type, INPUT);
	EXPECT_EQ(trass[1].x, 2);
	EXPECT_EQ(trass[1].y, 2);
	EXPECT_EQ(trass[1].connected_num, -1);

	EXPECT_EQ(trass[2].type, INPUT);
	EXPECT_EQ(trass[2].x, 2);
	EXPECT_EQ(trass[2].y, 3);
	EXPECT_EQ(trass[2].connected_num, -1);
	delete[] trass;
}
TEST(Contact, IstreamOverload)
{
	int x, y, type, cn;
	Contact c(INPUT, 24, 4);
	stringstream Nstream;
	Nstream << c;
	Nstream >> type >> x >> y >> cn;
	EXPECT_EQ(type, 1);
	EXPECT_EQ(x, 24);
	EXPECT_EQ(y, 4);
	EXPECT_EQ(cn, -1);
}
TEST(Contact, OutstreamOverload)
{
	int x, y, type, cn;
	Contact c(INPUT, 24, 4);
	stringstream Nstream;
	Nstream << c;
	Nstream >> type >> x >> y >> cn;
	EXPECT_EQ(type, 1);
	EXPECT_EQ(x, 24);
	EXPECT_EQ(y, 4);
	EXPECT_EQ(cn, -1);
}
TEST(PCB, AddOverload)
{
	PCB pcb;
	Contact* trass = new Contact[1];
	Contact c1 = Contact(OUTPUT, 1, 2);
	pcb += c1;
	pcb.get_Contacts(trass);

	EXPECT_EQ(pcb.get_Inputs(), 0);
	EXPECT_EQ(pcb.get_Outputs(), 1);
	EXPECT_EQ(trass[0].type, 0);
	EXPECT_EQ(trass[0].x, 1);
	EXPECT_EQ(trass[0].y, 2);
	EXPECT_EQ(trass[0].connected_num, -1);
	delete[] trass;
}
TEST(PCB, IndexOverload)
{
	PCB pcb;
	pcb.add_contact(INPUT, 2, 2);
	pcb.add_contact(INPUT, 1, 7);
	pcb.add_contact(INPUT, 3, 9);
	Contact c = pcb[2];
	EXPECT_EQ(c.type, INPUT);
	EXPECT_EQ(c.x, 3);
	EXPECT_EQ(c.y, 9);
}
TEST(PCB, DecrementPrefixOverload)
{
	PCB pcb = PCB(1, 2, 3);
	pcb.add_contact(INPUT, 2, 2);
	--pcb;
	EXPECT_EQ(pcb.get_Inputs(), 1);
	EXPECT_EQ(pcb.get_Outputs(), 0);
}
TEST(PCB, DecrementPostfixOverload)
{
	PCB pcb = PCB(0, 2, 3);
	pcb.add_contact(INPUT, 2, 2);
	pcb--;
	EXPECT_EQ(pcb.get_Inputs(), 0);
	EXPECT_EQ(pcb.get_Outputs(), 1);
}
TEST(PCB, DefaultConstructor)
{
	PCB pcb;
	EXPECT_EQ(pcb.get_Inputs(), 0);
	EXPECT_EQ(pcb.get_Outputs(), 0);
}
TEST(PCB, CopyConstructor)
{
	PCB pcb = PCB(1,2,8);
	PCB pcb2(pcb);
	Contact* trass = new Contact[1];
	pcb2.get_Contacts(trass);
	EXPECT_EQ(pcb2.get_Inputs(), 1);
	EXPECT_EQ(pcb2.get_Outputs(), 0);
	EXPECT_EQ(trass[0].type, INPUT);
	EXPECT_EQ(trass[0].x, 2);
	EXPECT_EQ(trass[0].y, 8);
	EXPECT_EQ(trass[0].connected_num, -1);
	delete[] trass;
}
TEST(PCB, MoveConstructor)
{
	PCB pcb = PCB(0,12,2);
	pcb.add_contact(Contact(INPUT, 1, 1));
	PCB pcb2(move(pcb));
	Contact* trass = new Contact[2];
	pcb2.get_Contacts(trass);
	EXPECT_EQ(pcb2.get_Inputs(), 1);
	EXPECT_EQ(pcb2.get_Outputs(), 1);
	EXPECT_EQ(trass[0].type, OUTPUT);
	EXPECT_EQ(trass[0].x, 12);
	EXPECT_EQ(trass[0].y, 2);
	EXPECT_EQ(trass[0].connected_num, -1);

	EXPECT_EQ(trass[1].type, INPUT);
	EXPECT_EQ(trass[1].x, 1);
	EXPECT_EQ(trass[1].y, 1);
	EXPECT_EQ(trass[1].connected_num, -1);
	delete[] trass;
}
TEST(PCB, AddContact)
{
	Contact* trass = new Contact[2];
	PCB pcb;
	pcb.add_contact(Contact(OUTPUT, 1, 2));
	pcb.get_Contacts(trass);

	EXPECT_EQ(pcb.get_Inputs(), 0);
	EXPECT_EQ(pcb.get_Outputs(), 1);
	EXPECT_EQ(trass[0].type, 0);
	EXPECT_EQ(trass[0].x, 1);
	EXPECT_EQ(trass[0].y, 2);
	EXPECT_EQ(trass[0].connected_num, -1);

	pcb.add_contact(Contact(INPUT, 2, 4));
	pcb.get_Contacts(trass);
	EXPECT_EQ(pcb.get_Inputs(), 1);
	EXPECT_EQ(pcb.get_Outputs(), 1);
	EXPECT_EQ(trass[1].type, 1);
	EXPECT_EQ(trass[1].x, 2);
	EXPECT_EQ(trass[1].y, 4);
	EXPECT_EQ(trass[1].connected_num, -1);
	delete[] trass;
}
TEST(PCB, RandConstructorError)
{
	EXPECT_THROW(PCB(-2, 1), std::invalid_argument);
	EXPECT_THROW(PCB(2, -1), std::invalid_argument);
}
TEST(PCB, AddContactError)
{
	PCB pcb;
	pcb.add_contact(OUTPUT, 1, 5);
	EXPECT_THROW(pcb.add_contact(Contact(OUTPUT, 1, 5)), std::invalid_argument);
	EXPECT_THROW(pcb.add_contact(Contact(INPUT, 1, 5)), std::invalid_argument);
}
TEST(PCB, AddContactByParametrsError)
{
	PCB pcb;
	pcb.add_contact(INPUT, 2, 4);
	EXPECT_THROW(pcb.add_contact(INPUT, 2, 4), std::invalid_argument);
	EXPECT_THROW(pcb.add_contact(OUTPUT, 2, 4), std::invalid_argument);
}
TEST(PCB, CreateContact)
{
	PCB pcb;
	pcb.add_contact(INPUT, 2, 4);
	pcb.add_contact(OUTPUT, 11, 3);
	Contact* trass = new Contact[2];
	pcb.get_Contacts(trass);
	EXPECT_EQ(pcb.get_Inputs(), 1);
	EXPECT_EQ(pcb.get_Outputs(), 1);
	EXPECT_EQ(trass[0].type, INPUT);
	EXPECT_EQ(trass[0].x, 2);
	EXPECT_EQ(trass[0].y, 4);
	EXPECT_EQ(trass[0].connected_num, -1);

	EXPECT_EQ(trass[1].type, OUTPUT);
	EXPECT_EQ(trass[1].x, 11);
	EXPECT_EQ(trass[1].y, 3);
	EXPECT_EQ(trass[1].connected_num, -1);
	delete[] trass;
}

TEST(PCB, Connect)
{
	PCB pcb;
	pcb.add_contact(Contact(OUTPUT, 1, 2));
	pcb.add_contact(Contact(INPUT, 2, 2));
	Contact* trass = new Contact[5];
	pcb.connect(0, 1);
	pcb.get_Contacts(trass);
	EXPECT_EQ(trass[0].connected_num, 1);
	EXPECT_EQ(trass[1].connected_num, 0);
	delete[] trass;
}
TEST(PCB, ConnectError)
{
	PCB pcb;
	EXPECT_THROW(pcb.connect(1, 2), std::invalid_argument);
	EXPECT_THROW(pcb.connect(2, 3), std::invalid_argument);
	pcb.add_contact(Contact(OUTPUT, 1, 2));
	pcb.add_contact(Contact(OUTPUT, 6, 2));
	EXPECT_THROW(pcb.connect(2, 3), std::invalid_argument);
}
TEST(PCB, Length)
{
	PCB pcb;
	pcb.add_contact(OUTPUT, 2, 1);
	pcb.add_contact(INPUT, 23, 12);
	EXPECT_EQ(pcb.length(0,1) , 24);
}
TEST(PCB, LengthError)
{
	PCB pcb;
	pcb.add_contact(OUTPUT, 2, 1);
	pcb.add_contact(OUTPUT, 23, 12);
	EXPECT_THROW(pcb.length(1, 5), std::logic_error);
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}