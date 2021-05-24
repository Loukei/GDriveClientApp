#ifndef MAINWINDOW_SETTINGS_H
#define MAINWINDOW_SETTINGS_H
#include <QSettings>
#include <QRect>
#include <QUrl>
/*!
 * \namespace Settings
 * \brief Settings is used for collect all settings key and read settings
 */
namespace Settings
{
/*定義變數名*/
extern const QString key_AppVersion = QStringLiteral("App/Version");
extern const QString key_Geometry = QStringLiteral("MainWindow/Geometry");
extern const QString key_Upload_FilePath = QStringLiteral("MainWindow/DialogUpload/FilePath");
extern const QString key_Download_FilePath = QStringLiteral("MainWindow/DialogDownload/FilePath");
extern const QString key_Download_FileID = QStringLiteral("MainWindow/DialogDownload/FileID");
extern const QString key_FileGet_FileID = QStringLiteral("MainWindow/DialogFileMataData/FileID");
extern const QString key_FileGet_Fields = QStringLiteral("MainWindow/DialogFileMataData/Fields");
extern const QString key_Update_FilePath = QStringLiteral("MainWindow/DialogUpdate/FilePath");
extern const QString key_Update_FileID = QStringLiteral("MainWindow/DialogUpdate/FileID");
extern const QString key_Account_Email = QStringLiteral("Account/Email");
extern const QString key_Account_IsRememberMe = QStringLiteral("Account/IsRememberMe");
extern const QString key_Account_RefreshToken = QStringLiteral("Account/RefreshToken");
extern const QString key_OAuth_ClientId = QStringLiteral("OAuth/ClientId");
extern const QString key_OAuth_ClientSecert = QStringLiteral("OAuth/ClientSecert");
extern const QString key_OAuth_RedirectUri = QStringLiteral("OAuth/RedirectUri");
extern const QString key_OAuth_RedirectPort = QStringLiteral("OAuth/RedirectPort");
extern const QString key_OAuth_Scope = QStringLiteral("OAuth/Scope");
extern const QString key_OAuth_AuthUri = QStringLiteral("OAuth/AuthUri");
extern const QString key_OAuth_TokenUri = QStringLiteral("OAuth/TokenUri");

/*Settings reader function*/
inline QString App_Version(const QSettings *settings){
    return settings->value(key_AppVersion,QStringLiteral("0.0.0")).toString();
}

inline QRect MainWindow_Geometry(const QSettings *settings){
    return settings->value(key_Geometry,QRect(0,0,630,495)).toRect();
}

inline QString Upload_FilePath(const QSettings *settings){
    return settings->value(key_Upload_FilePath).toString();
}

inline QString Download_FilePath(const QSettings *settings){
    return settings->value(key_Download_FilePath).toString();
}

inline QString Download_FileID(const QSettings *settings){
    return settings->value(key_Download_FileID).toString();
}

inline QString FileGet_FileID(const QSettings *settings){
    return settings->value(key_FileGet_FileID).toString();
}

inline QString FileGet_Fields(const QSettings *settings){
    return settings->value(key_FileGet_Fields).toString();
}

inline QString Update_FilePath(const QSettings *settings){
    return settings->value(key_Update_FilePath).toString();
}

inline QString Update_FileID(const QSettings *settings){
    return settings->value(key_Update_FileID).toString();
}

inline QString Account_Email(const QSettings *settings){
    return settings->value(key_Account_Email,QString()).toString();
}

inline QString Account_RefreshToken(const QSettings *settings){
    return settings->value(key_Account_RefreshToken,QString()).toString();
}

inline bool Account_IsRememberMe(const QSettings *settings){
    return settings->value(key_Account_IsRememberMe,bool(false)).toBool();
}

inline QString OAuth_ClientId(const QSettings *settings){
    return settings->value(key_OAuth_ClientId,"").toString();
}

inline QString OAuth_ClientSecert(const QSettings *settings){
    return settings->value(key_OAuth_ClientSecert,"").toString();
}

inline QUrl OAuth_RedirectUri(const QSettings *settings){
    return settings->value(key_OAuth_RedirectUri,"http://localhost:8080/cb").toUrl();
}

inline quint16 OAuth_RedirectPort(const QSettings *settings){
    return settings->value(key_OAuth_RedirectPort,OAuth_RedirectUri(settings).port()).toUInt();
}

//! file scope only able to download file form api uploaded
inline QString OAuth_Scope(const QSettings *settings){
    return settings->value(key_OAuth_Scope,"https://www.googleapis.com/auth/drive.file").toString();
}

inline QUrl OAuth_AuthUri(const QSettings *settings){
    return settings->value(key_OAuth_AuthUri,"https://accounts.google.com/o/oauth2/auth").toUrl();
}

inline QUrl OAuth_TokenUri(const QSettings *settings){
    return settings->value(key_OAuth_TokenUri,"https://oauth2.googleapis.com/token").toUrl();
}
} // Settings

#endif // MAINWINDOW_SETTINGS_H
