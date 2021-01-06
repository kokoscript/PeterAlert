VERSION 5.00
Begin VB.Form MainWin 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Peter Alert"
   ClientHeight    =   1680
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   2640
   Icon            =   "PeterAlert.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1680
   ScaleWidth      =   2640
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "OK"
      Height          =   375
      Left            =   840
      TabIndex        =   0
      Top             =   1080
      Width           =   975
   End
   Begin VB.Image Image1 
      Height          =   480
      Left            =   1080
      Picture         =   "PeterAlert.frx":000C
      Top             =   360
      Width           =   480
   End
End
Attribute VB_Name = "MainWin"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    End
End Sub

Private Sub Form_Load()
    Interaction.Beep
End Sub
