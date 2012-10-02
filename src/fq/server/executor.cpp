#include <iostream>
#include <string>

#include <boost/random.hpp> // #include <random> // for c++11
#include <quickfix/Exceptions.h>
#include <quickfix/FixFields.h>
#include <quickfix/fix44/NewOrderSingle.h>
#include <quickfix/fix44/MarketDataRequest.h>
#include <quickfix/fix44/MarketDataRequestReject.h>
#include <quickfix/fix44/MarketDataIncrementalRefresh.h>
#include <quickfix/fix44/MarketDataSnapshotFullRefresh.h>
#include <quickfix/fix44/Logon.h>
#include <quickfix/Session.h>

#include "executor.h"

using namespace std;
using namespace boost::random;

namespace FreeQuant { namespace Server {

void Executor::onCreate(const FIX::SessionID& sessionId) {
    cerr << "Executor::onCreate" << endl;
}


void Executor::onLogon(const FIX::SessionID& sessionId) {
    cerr << "Executor::onLogon" << endl;
}


void Executor::onLogout(const FIX::SessionID& sessionId) {
    cerr << "Executor::onLogout" << endl;
}

void Executor::toAdmin(FIX::Message& message, const FIX::SessionID& sessionId) {
//    cerr << "Executor::toAdmin" << endl;
}

void Executor::toApp(FIX::Message& message, const FIX::SessionID& sessionId) throw(FIX::DoNotSend) {
//    cerr << "Executor::toApp" << endl;

}

void Executor::fromAdmin(const FIX::Message& message, const FIX::SessionID& sessionId)
        throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon) {
//    cerr << "Executor::fromAdmin" << endl;
    crack(message, sessionId);
}

void Executor::fromApp( const FIX::Message& message, const FIX::SessionID& sessionId )
        throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType ) {
//    cerr << "Executor::fromApp" << endl;
    crack(message, sessionId);
}

void Executor::onMessage(const FIX44::NewOrderSingle& message, const FIX::SessionID& sessionId) {
    mt19937 rng;
    uniform_int_distribution<> six(1,6);

//    FIX::Symbol symbol;
//  FIX::Side side;
//  FIX::OrdType ordType;
//  FIX::OrderQty orderQty;
//  FIX::Price price;
//  FIX::ClOrdID clOrdID;
//  FIX::Account account;

//  message.get( ordType );

//  if ( ordType != FIX::OrdType_LIMIT )
//    throw FIX::IncorrectTagValue( ordType.getField() );

//  message.get( symbol );
//  message.get( side );
//  message.get( orderQty );
//  message.get( price );
//  message.get( clOrdID );

//  FIX44::ExecutionReport executionReport = FIX44::ExecutionReport
//      ( FIX::OrderID( genOrderID() ),
//        FIX::ExecID( genExecID() ),
//        FIX::ExecType( FIX::ExecType_FILL ),
//        FIX::OrdStatus( FIX::OrdStatus_FILLED ),
//        side,
//        FIX::LeavesQty( 0 ),
//        FIX::CumQty( orderQty ),
//        FIX::AvgPx( price ) );

//  executionReport.set( clOrdID );
//  executionReport.set( symbol );
//  executionReport.set( orderQty );
//  executionReport.set( FIX::LastQty( orderQty ) );
//  executionReport.set( FIX::LastPx( price ) );

//  if( message.isSet(account) )
//    executionReport.setField( message.get(account) );

//  try
//  {
//    FIX::Session::sendToTarget( executionReport, sessionId );
//  }
//  catch (FIX::SessionNotFound&) {}
}

void Executor::onMessage(const FIX44::Logon& message, const FIX::SessionID& sessionId) {
    FIX::Username username;
    FIX::Password password;
    cout << message.toXML() << endl;
//    message.get(username);
//    message.get(password);

//    cout << username << password << endl;
    string expected  = "12345";

//    if (password != expected) {
//         throw new FIX::RejectLogon();
//    }
}

void Executor::onMessage(const FIX44::MarketDataRequest& message, const FIX::SessionID& sessionId) {
    cerr << " Executor::onMessage(const FIX44::MarketDataRequest& message" << endl;

    FIX::MDReqID mdReqID;
    FIX::SubscriptionRequestType subscriptionRequestType;
    FIX::MarketDepth marketDepth;
    FIX::MDUpdateType mdUpdateType;
    FIX::AggregatedBook aggregatedBook;
    FIX::OpenCloseSettleFlag settleFlag;
    FIX::Scope scope;
    FIX::MDImplicitDelete mdImplicitDelete;
    FIX::NoMDEntryTypes noMDEntryTypes;

    message.get(mdReqID);
    message.get(subscriptionRequestType);
    message.get(marketDepth);
    message.get(mdUpdateType);
    message.get(aggregatedBook);
    message.get(scope);
    message.get(mdImplicitDelete);
    message.get(noMDEntryTypes);

    FIX44::MarketDataSnapshotFullRefresh mdFull;

    mdFull.set(mdReqID);
    mdFull.set(FIX::Symbol("GOOG"));
//    mdFull.set(FIX::SecurityID("GOOG"));
//    mdFull.set(FIX::SecurityIDSource());
//    mdFull.set(FIX::Product());
//    mdFull.set(FIX::CFICode());
//    mdFull.set(FIX::SecurityType(FIX::SecurityType_COMMONSTOCK));
//    mdFull.set(FIX::MaturityMonthYear("2012"));
//    mdFull.set(FIX::MaturityDate("2012-12-11"));
//    mdFull.set(FIX::CouponPaymentDate("2012-12-11"));
//    mdFull.set(FIX::IssueDate("2012-12-11"));
//    mdFull.set(FIX::RepoCollateralSecurityType(1));
//    mdFull.set(FIX::RepurchaseTerm(1));
//    mdFull.set(FIX::RepurchaseRate(0.3));
//    mdFull.set(FIX::Factor(0.1));
//    mdFull.set(FIX::CreditRating("AAA"));
//    mdFull.set(FIX::InstrRegistry("DD"));
//    mdFull.set(FIX::CountryOfIssue);
//    mdFull.set(FIX::StateOrProvinceOfIssue);
//    mdFull.set(FIX::LocaleOfIssue);
//    mdFull.set(FIX::RedemptionDate);
//    mdFull.set(FIX::StrikePrice(99.99));
//    mdFull.set(FIX::OptAttribute('d'));
//    mdFull.set(FIX::ContractMultiplier(1));
//    mdFull.set(FIX::CouponRate(0.2));
//    mdFull.set(FIX::SecurityExchange("NYEX"));
//    mdFull.set(FIX::Issuer("sf"));
//    mdFull.set(FIX::EncodedIssuerLen(10));
//    mdFull.set(FIX::EncodedIssuer("sf"));
//    mdFull.set(FIX::SecurityDesc("dadad"));
//    mdFull.set(FIX::EncodedSecurityDescLen(20));
//    mdFull.set(FIX::EncodedSecurityDesc("fdfs"));
//    mdFull.set(FIX::NoSecurityAltID(1));

//    mdInc.set(mdReqID);
//    FIX::NoMDEntries count;

    mdFull.set(FIX::NoMDEntries(2));
    FIX44::MarketDataSnapshotFullRefresh::NoMDEntries mdEntries1;
    mdEntries1.set(FIX::MDEntryType(FIX::MDEntryType_BID));
    mdEntries1.set(FIX::MDEntryPx(100));
    mdEntries1.set(FIX::MDEntrySize(1));

    mdFull.addGroup(mdEntries1);
    FIX44::MarketDataSnapshotFullRefresh::NoMDEntries mdEntries2;
    mdEntries2.set(FIX::MDEntryType(FIX::MDEntryType_OFFER));
    mdEntries2.set(FIX::MDEntryPx(110));
    mdEntries2.set(FIX::MDEntrySize(2));

    mdFull.addGroup(mdEntries2);

    try {
        FIX::Session::sendToTarget(mdFull, sessionId);
    } catch (FIX::SessionNotFound&) {}
}

}}
