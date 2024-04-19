#pragma once

#define KEYCODE_FROM_SCANCODE(X) SDL_SCANCODE_TO_KEYCODE(int32((X)))
enum class Keycode: int32
{
    Unknown=0,

    Return='\r',
    Escape='\033',
    Backspace='\b',
    Tab='\t',
    Space=' ',
    Exclaim='!',
    Quotedbl='"',
    Hash='#',
    Percent='%',
    Dollar='$',
    Ampersand='&',
    Quote='\'',
    Leftparen='(',
    Rightparen=')',
    Asterisk='*',
    Plus='+',
    Comma=',',
    Minus='-',
    Period='.',
    Slash='/',
    N0='0',
    N1='1',
    N2='2',
    N3='3',
    N4='4',
    N5='5',
    N6='6',
    N7='7',
    N8='8',
    N9='9',
    Colon=':',
    Semicolon=';',
    Less='<',
    Equals='=',
    Greater='>',
    Question='?',
    At='@',
		//Skip Uppercase Letters
    Leftbracket='[',
    Backslash='\\',
    Rightbracket=']',
    Caret='^',
    Underscore='_',
    Backquote='`',
    A='a',
    B='b',
    C='c',
    D='d',
    E='e',
    F='f',
    G='g',
    H='h',
    I='i',
    J='j',
    K='k',
    L='l',
    M='m',
    N='n',
    O='o',
    P='p',
    Q='q',
    R='r',
    S='s',
    T='t',
    U='u',
    V='v',
    W='w',
    X='x',
    Y='y',
    Z='z',

    Capslock=KEYCODE_FROM_SCANCODE(Scancode::CapsLock),
    F1=KEYCODE_FROM_SCANCODE(Scancode::F1),
    F2=KEYCODE_FROM_SCANCODE(Scancode::F2),
    F3=KEYCODE_FROM_SCANCODE(Scancode::F3),
    F4=KEYCODE_FROM_SCANCODE(Scancode::F4),
    F5=KEYCODE_FROM_SCANCODE(Scancode::F5),
    F6=KEYCODE_FROM_SCANCODE(Scancode::F6),
    F7=KEYCODE_FROM_SCANCODE(Scancode::F7),
    F8=KEYCODE_FROM_SCANCODE(Scancode::F8),
    F9=KEYCODE_FROM_SCANCODE(Scancode::F9),
    F10=KEYCODE_FROM_SCANCODE(Scancode::F10),
    F11=KEYCODE_FROM_SCANCODE(Scancode::F11),
    F12=KEYCODE_FROM_SCANCODE(Scancode::F12),

    Printscreen=KEYCODE_FROM_SCANCODE(Scancode::PrintScreen),
    Scrolllock=KEYCODE_FROM_SCANCODE(Scancode::ScrollLock),
    Pause=KEYCODE_FROM_SCANCODE(Scancode::Pause),
    Insert=KEYCODE_FROM_SCANCODE(Scancode::Insert),
    Home=KEYCODE_FROM_SCANCODE(Scancode::Home),
    Pageup=KEYCODE_FROM_SCANCODE(Scancode::PageUp),
    Delete='\177',
    End=KEYCODE_FROM_SCANCODE(Scancode::End),
    Pagedown=KEYCODE_FROM_SCANCODE(Scancode::PageDown),
    Right=KEYCODE_FROM_SCANCODE(Scancode::Right),
    Left=KEYCODE_FROM_SCANCODE(Scancode::Left),
    Down=KEYCODE_FROM_SCANCODE(Scancode::Down),
    Up=KEYCODE_FROM_SCANCODE(Scancode::Up),

    NumLockOrClear=KEYCODE_FROM_SCANCODE(Scancode::NumLockOrClear),
    KpDivide=KEYCODE_FROM_SCANCODE(Scancode::KpDivide),
    KpMultiply=KEYCODE_FROM_SCANCODE(Scancode::KpMultiply),
    KpMinus=KEYCODE_FROM_SCANCODE(Scancode::KpMinus),
    KpPlus=KEYCODE_FROM_SCANCODE(Scancode::KpPlus),
    KpEnter=KEYCODE_FROM_SCANCODE(Scancode::KpEnter),
    Kp1=KEYCODE_FROM_SCANCODE(Scancode::Kp1),
    Kp2=KEYCODE_FROM_SCANCODE(Scancode::Kp2),
    Kp3=KEYCODE_FROM_SCANCODE(Scancode::Kp3),
    Kp4=KEYCODE_FROM_SCANCODE(Scancode::Kp4),
    Kp5=KEYCODE_FROM_SCANCODE(Scancode::Kp5),
    Kp6=KEYCODE_FROM_SCANCODE(Scancode::Kp6),
    Kp7=KEYCODE_FROM_SCANCODE(Scancode::Kp7),
    Kp8=KEYCODE_FROM_SCANCODE(Scancode::Kp8),
    Kp9=KEYCODE_FROM_SCANCODE(Scancode::Kp9),
    Kp0=KEYCODE_FROM_SCANCODE(Scancode::Kp0),
    KpPeriod=KEYCODE_FROM_SCANCODE(Scancode::KpPeriod),

    Application=KEYCODE_FROM_SCANCODE(Scancode::Application),
    Power=KEYCODE_FROM_SCANCODE(Scancode::Power),
    KpEquals=KEYCODE_FROM_SCANCODE(Scancode::KpEquals),
    F13=KEYCODE_FROM_SCANCODE(Scancode::F13),
    F14=KEYCODE_FROM_SCANCODE(Scancode::F14),
    F15=KEYCODE_FROM_SCANCODE(Scancode::F15),
    F16=KEYCODE_FROM_SCANCODE(Scancode::F16),
    F17=KEYCODE_FROM_SCANCODE(Scancode::F17),
    F18=KEYCODE_FROM_SCANCODE(Scancode::F18),
    F19=KEYCODE_FROM_SCANCODE(Scancode::F19),
    F20=KEYCODE_FROM_SCANCODE(Scancode::F20),
    F21=KEYCODE_FROM_SCANCODE(Scancode::F21),
    F22=KEYCODE_FROM_SCANCODE(Scancode::F22),
    F23=KEYCODE_FROM_SCANCODE(Scancode::F23),
    F24=KEYCODE_FROM_SCANCODE(Scancode::F24),
    Execute=KEYCODE_FROM_SCANCODE(Scancode::Execute),
    Help=KEYCODE_FROM_SCANCODE(Scancode::Help),
    Menu=KEYCODE_FROM_SCANCODE(Scancode::Menu),
    Select=KEYCODE_FROM_SCANCODE(Scancode::Select),
    Stop=KEYCODE_FROM_SCANCODE(Scancode::Stop),
    Again=KEYCODE_FROM_SCANCODE(Scancode::Again),
    Undo=KEYCODE_FROM_SCANCODE(Scancode::Undo),
    Cut=KEYCODE_FROM_SCANCODE(Scancode::Cut),
    Copy=KEYCODE_FROM_SCANCODE(Scancode::Copy),
    Paste=KEYCODE_FROM_SCANCODE(Scancode::Paste),
    Find=KEYCODE_FROM_SCANCODE(Scancode::Find),
    Mute=KEYCODE_FROM_SCANCODE(Scancode::Mute),
    VolumeUp=KEYCODE_FROM_SCANCODE(Scancode::VolumeUp),
    VolumeDown=KEYCODE_FROM_SCANCODE(Scancode::VolumeDown),
    KpComma=KEYCODE_FROM_SCANCODE(Scancode::KpComma),
    KpEqualsAs400=KEYCODE_FROM_SCANCODE(Scancode::KpEqualsAs400),

    AltErase=KEYCODE_FROM_SCANCODE(Scancode::AltErase),
    SysReq=KEYCODE_FROM_SCANCODE(Scancode::SysReq),
    Cancel=KEYCODE_FROM_SCANCODE(Scancode::Cancel),
    Clear=KEYCODE_FROM_SCANCODE(Scancode::Clear),
    Prior=KEYCODE_FROM_SCANCODE(Scancode::Prior),
    Return2=KEYCODE_FROM_SCANCODE(Scancode::Return2),
    Separator=KEYCODE_FROM_SCANCODE(Scancode::Separator),
    Out=KEYCODE_FROM_SCANCODE(Scancode::Out),
    Oper=KEYCODE_FROM_SCANCODE(Scancode::Oper),
    ClearAgain=KEYCODE_FROM_SCANCODE(Scancode::ClearAgain),
    CrSel=KEYCODE_FROM_SCANCODE(Scancode::CrSel),
    ExSel=KEYCODE_FROM_SCANCODE(Scancode::ExSel),

    Kp00=KEYCODE_FROM_SCANCODE(Scancode::Kp00),
    Kp000=KEYCODE_FROM_SCANCODE(Scancode::Kp000),
    ThousandsSeparator=KEYCODE_FROM_SCANCODE(Scancode::ThousandsSeparator),
    DecimalSeparator=KEYCODE_FROM_SCANCODE(Scancode::DecimalSeparator),
    CurrencyUnit=KEYCODE_FROM_SCANCODE(Scancode::CurrencyUnit),
    CurrencySubunit=KEYCODE_FROM_SCANCODE(Scancode::CurrencySubunit),

    KpLeftparen=KEYCODE_FROM_SCANCODE(Scancode::KpLeftParen),
    KpRightparen=KEYCODE_FROM_SCANCODE(Scancode::KpRightParen),
    KpLeftbrace=KEYCODE_FROM_SCANCODE(Scancode::KpLeftBrace),
    KpRightbrace=KEYCODE_FROM_SCANCODE(Scancode::KpRightBrace),
    KpTab=KEYCODE_FROM_SCANCODE(Scancode::KpTab),
    KpBackspace=KEYCODE_FROM_SCANCODE(Scancode::KpBackspace),
    KpA=KEYCODE_FROM_SCANCODE(Scancode::KpA),
    KpB=KEYCODE_FROM_SCANCODE(Scancode::KpB),
    KpC=KEYCODE_FROM_SCANCODE(Scancode::KpC),
    KpD=KEYCODE_FROM_SCANCODE(Scancode::KpD),
    KpE=KEYCODE_FROM_SCANCODE(Scancode::KpE),
    KpF=KEYCODE_FROM_SCANCODE(Scancode::KpF),
    KpXor=KEYCODE_FROM_SCANCODE(Scancode::KpXor),
    KpPower=KEYCODE_FROM_SCANCODE(Scancode::KpPower),
    KpPercent=KEYCODE_FROM_SCANCODE(Scancode::KpPercent),
    KpLess=KEYCODE_FROM_SCANCODE(Scancode::KpLess),
    KpGreater=KEYCODE_FROM_SCANCODE(Scancode::KpGreater),
    KpAmpersand=KEYCODE_FROM_SCANCODE(Scancode::KpAmpersand),

    KpBblAmpersand=KEYCODE_FROM_SCANCODE(Scancode::KpDblAmpersand),
    KpVerticalBar=KEYCODE_FROM_SCANCODE(Scancode::KpVerticalBar),
    KpDblVerticalBar=KEYCODE_FROM_SCANCODE(Scancode::KpDblVerticalBar),

    KpColon=KEYCODE_FROM_SCANCODE(Scancode::KpColon),
    KpHash=KEYCODE_FROM_SCANCODE(Scancode::KpHash),
    KpSpace=KEYCODE_FROM_SCANCODE(Scancode::KpSpace),
    KpAt=KEYCODE_FROM_SCANCODE(Scancode::KpAt),
    KpExclam=KEYCODE_FROM_SCANCODE(Scancode::KpExclam),
    KpMemStore=KEYCODE_FROM_SCANCODE(Scancode::KpMemStore),
    KpMemRecall=KEYCODE_FROM_SCANCODE(Scancode::KpMemRecall),
    KpMemClear=KEYCODE_FROM_SCANCODE(Scancode::KpMemClear),
    KpMemAdd=KEYCODE_FROM_SCANCODE(Scancode::KpMemAdd),

    KpMemSubstract=KEYCODE_FROM_SCANCODE(Scancode::KpMemSubstract),
    KpMemMultiply=KEYCODE_FROM_SCANCODE(Scancode::KpMemMultiply),

    KpMemDivide=KEYCODE_FROM_SCANCODE(Scancode::KpMemDivide),
    KpPlusMinus=KEYCODE_FROM_SCANCODE(Scancode::KpPlusMinus),
    KpClear=KEYCODE_FROM_SCANCODE(Scancode::KpClear),
    KpClearEntry=KEYCODE_FROM_SCANCODE(Scancode::KpClearEntry),
    KpBinary=KEYCODE_FROM_SCANCODE(Scancode::KpBinary),
    KpOctal=KEYCODE_FROM_SCANCODE(Scancode::KpOctal),
    KpDecimal=KEYCODE_FROM_SCANCODE(Scancode::KpDecimal),
    KpHexadecimal=KEYCODE_FROM_SCANCODE(Scancode::KpHexadecimal),

    LCtrl=KEYCODE_FROM_SCANCODE(Scancode::LCtrl),
    LShift=KEYCODE_FROM_SCANCODE(Scancode::LShift),
    LAlt=KEYCODE_FROM_SCANCODE(Scancode::LAlt),
    LGUI=KEYCODE_FROM_SCANCODE(Scancode::LGUI),
    RCtrl=KEYCODE_FROM_SCANCODE(Scancode::RCtrl),
    RShift=KEYCODE_FROM_SCANCODE(Scancode::RShift),
    RAlt=KEYCODE_FROM_SCANCODE(Scancode::RAlt),
    RGUI=KEYCODE_FROM_SCANCODE(Scancode::RGUI),

    Mode=KEYCODE_FROM_SCANCODE(Scancode::Mode),

    AudioNext=KEYCODE_FROM_SCANCODE(Scancode::AudioNext),
    AudioPrev=KEYCODE_FROM_SCANCODE(Scancode::AudioPrev),
    AudioStop=KEYCODE_FROM_SCANCODE(Scancode::AudioStop),
    AudioPlay=KEYCODE_FROM_SCANCODE(Scancode::AudioPlay),
    AudioMute=KEYCODE_FROM_SCANCODE(Scancode::AudioMute),
    MediaSelect=KEYCODE_FROM_SCANCODE(Scancode::MediaSelect),
    Www=KEYCODE_FROM_SCANCODE(Scancode::Www),
    Mail=KEYCODE_FROM_SCANCODE(Scancode::Mail),
    Calculator=KEYCODE_FROM_SCANCODE(Scancode::Calculator),
    Computer=KEYCODE_FROM_SCANCODE(Scancode::Computer),
    AcSearch=KEYCODE_FROM_SCANCODE(Scancode::AcSearch),
    AcHome=KEYCODE_FROM_SCANCODE(Scancode::AcHome),
    AcBack=KEYCODE_FROM_SCANCODE(Scancode::AcBack),
    AcForward=KEYCODE_FROM_SCANCODE(Scancode::AcForward),
    AcStop=KEYCODE_FROM_SCANCODE(Scancode::AcStop),
    AcRefresh=KEYCODE_FROM_SCANCODE(Scancode::AcRefresh),
    AcBookmarks=KEYCODE_FROM_SCANCODE(Scancode::AcBookmarks),

    BrightnessDown=KEYCODE_FROM_SCANCODE(Scancode::BrightnessDown),
    BrightnessUp=KEYCODE_FROM_SCANCODE(Scancode::BrightnessUp),
    DisplaySwitch=KEYCODE_FROM_SCANCODE(Scancode::DisplaySwitch),
    KbDillumToggle=KEYCODE_FROM_SCANCODE(Scancode::KbDillumToggle),
    KbDillumDown=KEYCODE_FROM_SCANCODE(Scancode::KbDillumDown),
    KbDillumUp=KEYCODE_FROM_SCANCODE(Scancode::KbDillumUp),
    Eject=KEYCODE_FROM_SCANCODE(Scancode::Eject),
    Sleep=KEYCODE_FROM_SCANCODE(Scancode::Sleep)
};
#undef KEYCODE_FROM_SCANCODE