#include "pch.h"
#include <PCB.h>
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
	Contact contact = Contact(1, 2, 8);
	EXPECT_EQ(contact.type, 1);
	EXPECT_EQ(contact.x, 2);
	EXPECT_EQ(contact.y, 8);
	EXPECT_EQ(contact.connected_num, -1);

	contact = Contact(0, 3, 2);
	EXPECT_EQ(contact.type, 0);
	EXPECT_EQ(contact.x, 3);
	EXPECT_EQ(contact.y, 2);
	EXPECT_EQ(contact.connected_num, -1);
}
TEST(Contact, ConstructorError)
{
	EXPECT_THROW(Contact(9, 2, 2), std::invalid_argument);
	EXPECT_THROW(Contact(3, 2, 1), std::invalid_argument);
	EXPECT_THROW(Contact(7, 2, 2), std::invalid_argument);
	EXPECT_THROW(Contact(-2, 12, 2), std::invalid_argument);
}
TEST(PCB, DefaultConstructor)
{
	PCB pcb;
	EXPECT_EQ(pcb.get_Inputs(), 0);
	EXPECT_EQ(pcb.get_Outputs(), 0);
}
TEST(PCB, RandConstructor)
{
	PCB pcb = PCB(3, 6);
	EXPECT_EQ(pcb.get_Inputs(), 3);
	EXPECT_EQ(pcb.get_Outputs(), 6);

	pcb = PCB(9, 2);
	EXPECT_EQ(pcb.get_Inputs(), 9);
	EXPECT_EQ(pcb.get_Outputs(), 2);
}
TEST(PCB, AddContact)
{
	Contact* trass = new Contact[5];
	PCB pcb;
	pcb.add_contact(Contact(0, 1, 2));
	pcb.get_Contacts(trass);

	EXPECT_EQ(pcb.get_Inputs(), 0);
	EXPECT_EQ(pcb.get_Outputs(), 1);
	EXPECT_EQ(trass[0].type, 0);
	EXPECT_EQ(trass[0].x, 1);
	EXPECT_EQ(trass[0].y, 2);
	EXPECT_EQ(trass[0].connected_num, -1);

	pcb.add_contact(Contact(1, 2, 4));
	pcb.get_Contacts(trass);
	EXPECT_EQ(pcb.get_Inputs(), 1);
	EXPECT_EQ(pcb.get_Outputs(), 1);
	EXPECT_EQ(trass[1].type, 1);
	EXPECT_EQ(trass[1].x, 2);
	EXPECT_EQ(trass[1].y, 4);
	EXPECT_EQ(trass[1].connected_num, -1);
	delete[] trass;
}
TEST(PCB, AddContactError)
{
	PCB pcb = PCB();
	EXPECT_THROW(pcb.add_contact(Contact(-1, 2, 4)), std::invalid_argument);
	//EXPECT_THROW(pcb.add_contact(Contact(1, 1, 4)), std::logic_error);
}
TEST(PCB, CreateContact)
{
	PCB pcb = PCB(1, 1);
	Contact* trass = new Contact[5];
	pcb.add_contact(1, 2, 4);
	pcb.get_Contacts(trass);
	EXPECT_EQ(pcb.get_Inputs(), 2);
	EXPECT_EQ(pcb.get_Outputs(), 1);
	EXPECT_EQ(trass[2].type, 1);
	EXPECT_EQ(trass[2].x, 2);
	EXPECT_EQ(trass[2].y, 4);
	EXPECT_EQ(trass[2].connected_num, -1);

	pcb.add_contact(0, 1, 3);
	pcb.get_Contacts(trass);
	EXPECT_EQ(pcb.get_Inputs(), 2);
	EXPECT_EQ(pcb.get_Outputs(), 2);
	EXPECT_EQ(trass[3].type, 0);
	EXPECT_EQ(trass[3].x, 1);
	EXPECT_EQ(trass[3].y, 3);
	EXPECT_EQ(trass[3].connected_num, -1);
	delete[] trass;
}
TEST(PCB, CreateContactError)
{
	PCB pcb = PCB(11, 21);
	EXPECT_THROW(pcb.add_contact(Contact(-1, 2, 4)), std::invalid_argument);

}
TEST(PCB, Connect)
{
	PCB pcb = PCB(1, 1);
	Contact* trass = new Contact[5];
	pcb.connect(1, 2);
	pcb.get_Contacts(trass);
	EXPECT_EQ(trass[0].connected_num, 1);
	EXPECT_EQ(trass[1].connected_num, 0);
	delete[] trass;
}
TEST(PCB, ConnectError)
{
	PCB pcb = PCB(1, 1);
	Contact* trass = new Contact[5];
	pcb.connect(1, 2);
	pcb.get_Contacts(trass);
	EXPECT_EQ(trass[0].connected_num, 1);
	EXPECT_EQ(trass[1].connected_num, 0);
	delete[] trass;
}
TEST(PCB, Length)
{
	PCB pcb;
	pcb.add_contact(0, 2, 1);
	pcb.add_contact(0, 23, 12);
	EXPECT_EQ(pcb.length(1,2) , 24);
}
TEST(PCB, LengthError)
{
	PCB pcb;
	pcb.add_contact(0, 2, 1);
	pcb.add_contact(0, 23, 12);
	EXPECT_THROW(pcb.length(1, 5), std::logic_error);
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}