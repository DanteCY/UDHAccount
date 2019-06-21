Pod::Spec.new do |s|
  s.name                  = "UDHAccount"
  s.version               = "0.1.0"
  s.summary               = "An IoT Account."
  s.homepage              = "https://www.aliyun.com/"
  s.license               = { :type => 'Copyright', :text => "Alibaba-INC copyright" }
  s.author                = { "hcy" => "317727215@qq.com" }
  s.source                = { :git => "https://github.com/DanteCY/UDHAccount.git" }
  s.platform              = :ios, '8.0'
  s.vendored_frameworks = 'UDHAccount/UDHAccount.framework'
  s.frameworks = 'Foundation'
  s.requires_arc = true
  s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}
  
end
