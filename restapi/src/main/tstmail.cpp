#include <util/CSmtp.h>
#include <iostream>

int main()
{
	bool bError = false;

	try
	{
		CSmtp mail;
		mail.SetSMTPServer("smtp.gmail.com",465);
    		mail.SetSecurityType(USE_SSL);
		mail.m_bHTML =true;


	//	mail.SetSMTPServer("smtp.gmail.com",25);
		mail.SetLogin("varamballysanathkumar@gmail.com");
		mail.SetPassword("Gayathri123");
  		mail.SetSenderName("Sanath");
  		mail.SetSenderMail("varamballysanathkumar@gmail.com");
  		mail.SetReplyTo("varamballysanathkumar@gmail.com");
  		mail.SetSubject("The message");
  		mail.AddRecipient("sanathkumar.v@cspl.com");
  		mail.SetXPriority(XPRIORITY_NORMAL);
  		mail.SetXMailer("The Bat! (v3.02) Professional");
  		mail.AddMsgLine("<b>Hello,");
		mail.AddMsgLine("");
		mail.AddMsgLine("...");
		mail.AddMsgLine("How are you today?</b>");
		mail.AddMsgLine("");
		mail.AddMsgLine("Regards");
		mail.ModMsgLine(5,"regards");
		mail.DelMsgLine(2);
		mail.AddMsgLine("User");
		
  		//mail.AddAttachment("../test1.jpg");
  		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
		mail.Send();
	}
	catch(ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if(!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}

