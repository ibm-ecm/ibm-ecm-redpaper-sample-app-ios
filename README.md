# IBM® Enterprise Content Management Mobile Application Implementation Redpaper™ Sample Code

[![Swift 2.2](https://img.shields.io/badge/Swift-2.2-green.svg?style=flat)](https://developer.apple.com/swift/)

IBM® Enterprise Content Management (ECM) software enables the world's top companies to make better decisions, faster. By controlling content, companies can use industry-specific solutions to capture, manage, and share information. Successful organizations understand that business content matters more than ever as mobile, social, and cloud technologies transform their business models.

The IBM Redpaper™ publication introduces the mobile functionality offered in IBM Enterprise Content Management products: IBM Content Navigator, IBM Case manager, and IBM Datacap Mobile.

This repository contains sample implementations for the following scenarios:

* Simple usage of IBM Case Manager Mobile, leveraging location data ([IBM Case Manager Nearby Sample](IBM-CaseManagerNearbySample-iOS));
* Composite usage of IBM Datacap Mobile to capture data along with ICM Case Manager Mobile to file the data accordingly ([IBM Case Manager Capture Sample](IBM-CaseManagerCaptureSample-iOS)).

>You can visit [IBM Enterprise Content Management Mobile Application Implementation](http://www.redbooks.ibm.com/abstracts/redp5255.html) to find the publication and more information.

## Table of Contents
* [Requirements](#Requirements)
* [Building and Testing](#build--test)
* [Open Source @ IBM](#open-source--ibm)
* [License](#license)
* [Contributing](#contributing)

## Requirements

* ***Xcode*** 7.3 or greater;

This repository contains all necessary code and is self contained having no external dependencies.

## Build + Test

***Xcode*** is used to build the project for testing and deployment.

The sample is divided in two projects:

* IBM Case Manager Nearby Sample: [IBM-CaseManagerNearbySample-iOS.xcodeproj](IBM-CaseManagerNearbySample-iOS/IBM-CaseManagerNearbySample-iOS.xcodeproj)
* IBM Case Manager Capture Sample: [IBM-CaseManagerCaptureSample-iOS.xcodeproj](IBM-CaseManagerCaptureSample-iOS/IBM-CaseManagerCaptureSample-iOS.xcodeproj)

Alternatively you may open both project using [IBM-RedPaperSamples-iOS.xcworkspace](IBM-RedPaperSamples-iOS.xcworkspace)

### Parameter Configuration

#### IBM Case Manager Nearby Sample

IBM Case Manager configuration parameters can be found in [FWTMapViewController.swift](IBM-CaseManagerNearbySample-iOS/IBM-CaseManagerNearbySample-iOS/UI/FWTMapViewController.swift):

    let SimpleSampleBaseURLString = "http://ecmdev1.ibm.office.fwn:9080/navigator"  
    let SimpleSampleUsername = "p8admin"  
    let SimpleSamplePassword = "filenet"

#### IBM Case Manager Capture Sample

IBM Case Manager configuration parameters can be found in [FWTCoreManagerSessionConfiguration.swift](IBM-CaseManagerCaptureSample-iOS/IBM-CaseManagerCaptureSample-iOS/Service/FWTCoreManagerSessionConfiguration.swift):

    let serverHost = "http://ecm1.fws.io:9080/navigator"
    let user = "ecmexec"
    let password = "ecmexec"

IBM Datacap configuration parameters can be found in [FWTDatacapSessionConfiguration.swift](IBM-CaseManagerCaptureSample-iOS/IBM-CaseManagerCaptureSample-iOS/Service/FWTDatacapSessionConfiguration.swift):

    private let serverUrl = NSURL(string: "http://ecm1.fws.io:8070/servicewtm.svc")!
    private let username = "ecmexec"
    private let password = "ecmexec"
    private let stationId = "1"
    private let applicationId = "CarLoan"
    private let workflowId = "CarLoan"
    private let jobId = "Manual Select"
    private let dcoName = "CarLoan"

## Open Source @ IBM
Find more open source projects on the [IBM Github Page](http://ibm.github.io/)

## License

This library is licensed under Apache 2.0. Full license text is
available in [LICENSE](LICENSE).

This SDK is intended solely for use with an Apple iOS product and intended to be used in conjunction with officially licensed Apple development tools.

## Contributing

See [CONTRIBUTING](CONTRIBUTING.md) on how to help out.
