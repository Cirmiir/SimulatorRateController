BUILDDIR := build
SOURCEDIR:= src
NS3DIR	 := ns3
DEBUG	 := -g
all: main
main: $(BUILDDIR)/main.o $(BUILDDIR)/Client.o $(BUILDDIR)/Channel.o ns3 $(BUILDDIR)/Simulator.o $(BUILDDIR)/RateController.o $(BUILDDIR)/UserDatabase.o $(BUILDDIR)/RateDatabase.o $(BUILDDIR)/FrequencyController.o $(BUILDDIR)/FirstRateController.o $(BUILDDIR)/SecondRateController.o $(BUILDDIR)/ThirdRateController.o $(BUILDDIR)/UsuallyChannel.o $(BUILDDIR)/ChannelFactory.o $(BUILDDIR)/GreedChannel.o
	g++ $(DEBUG) -o  Simulator.out $(BUILDDIR)/Client.o $(BUILDDIR)/main.o $(BUILDDIR)/ipv4-address.o $(BUILDDIR)/address.o $(BUILDDIR)/attribute.o $(BUILDDIR)/log.o $(BUILDDIR)/tag-buffer.o $(BUILDDIR)/string.o $(BUILDDIR)/Channel.o $(BUILDDIR)/Simulator.o $(BUILDDIR)/RateController.o $(BUILDDIR)/UserDatabase.o $(BUILDDIR)/RateDatabase.o $(BUILDDIR)/FrequencyController.o $(BUILDDIR)/FirstRateController.o $(BUILDDIR)/SecondRateController.o $(BUILDDIR)/ThirdRateController.o $(BUILDDIR)/UsuallyChannel.o $(BUILDDIR)/ChannelFactory.o $(BUILDDIR)/GreedChannel.o
$(BUILDDIR)/main.o:	$(SOURCEDIR)/main.cc $(SOURCEDIR)/Client.h $(SOURCEDIR)/Rate.h
	g++ $(DEBUG) -c -o  $(BUILDDIR)/main.o $(SOURCEDIR)/main.cc
$(BUILDDIR)/FirstRateController.o: $(SOURCEDIR)/RateControllers/RateController.h $(SOURCEDIR)/RateControllers/FirstRateController.h $(SOURCEDIR)/RateControllers/FirstRateController.cc
	g++ $(DEBUG) -c -o  $(BUILDDIR)/FirstRateController.o $(SOURCEDIR)/RateControllers/FirstRateController.cc
$(BUILDDIR)/SecondRateController.o: $(SOURCEDIR)/RateControllers/RateController.h $(SOURCEDIR)/RateControllers/SecondRateController.h $(SOURCEDIR)/RateControllers/SecondRateController.cc
	g++ $(DEBUG) -c -o  $(BUILDDIR)/SecondRateController.o $(SOURCEDIR)/RateControllers/SecondRateController.cc
$(BUILDDIR)/ThirdRateController.o: $(SOURCEDIR)/RateControllers/RateController.h $(SOURCEDIR)/RateControllers/ThirdRateController.h $(SOURCEDIR)/RateControllers/ThirdRateController.cc
	g++ $(DEBUG) -c -o  $(BUILDDIR)/ThirdRateController.o $(SOURCEDIR)/RateControllers/ThirdRateController.cc
$(BUILDDIR)/RateController.o: $(SOURCEDIR)/RateControllers/RateController.h $(SOURCEDIR)/RateControllers/RateController.cc
	g++ $(DEBUG) -c -o  $(BUILDDIR)/RateController.o $(SOURCEDIR)/RateControllers/RateController.cc
$(BUILDDIR)/FrequencyController.o: $(SOURCEDIR)/FrequencyController.h $(SOURCEDIR)/FrequencyController.cc
	g++ $(DEBUG) -c -o  $(BUILDDIR)/FrequencyController.o $(SOURCEDIR)/FrequencyController.cc
$(BUILDDIR)/Simulator.o: $(SOURCEDIR)/Simulator.h $(SOURCEDIR)/Simulator.cc
	g++ $(DEBUG) -c -o  $(BUILDDIR)/Simulator.o $(SOURCEDIR)/Simulator.cc
$(BUILDDIR)/ChannelFactory.o: $(BUILDDIR)/Channel.o $(SOURCEDIR)/ChannelFactory.cc $(SOURCEDIR)/ChannelFactory.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/ChannelFactory.o $(SOURCEDIR)/ChannelFactory.cc
$(BUILDDIR)/GreedChannel.o: $(SOURCEDIR)/Channels/GreedChannel.h $(SOURCEDIR)/Channels/GreedChannel.cc $(SOURCEDIR)/Channel.h 
	g++ $(DEBUG) -c -o $(BUILDDIR)/GreedChannel.o $(SOURCEDIR)/Channels/GreedChannel.cc
$(BUILDDIR)/UsuallyChannel.o: $(SOURCEDIR)/Channels/UsuallyChannel.h $(SOURCEDIR)/Channels/UsuallyChannel.cc $(SOURCEDIR)/Channel.h 
	g++ $(DEBUG) -c -o $(BUILDDIR)/UsuallyChannel.o $(SOURCEDIR)/Channels/UsuallyChannel.cc
$(BUILDDIR)/Channel.o: $(SOURCEDIR)/Channel.h $(SOURCEDIR)/Channel.cc
	g++ $(DEBUG) -c -o $(BUILDDIR)/Channel.o $(SOURCEDIR)/Channel.cc
$(BUILDDIR)/Client.o: $(SOURCEDIR)/Client.h $(SOURCEDIR)/Client.cc $(SOURCEDIR)/$(NS3DIR)/ipv4-address.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/Client.o $(SOURCEDIR)/Client.cc
ns3: $(BUILDDIR)/UserDatabase.o $(BUILDDIR)/attribute.o $(BUILDDIR)/string.o $(BUILDDIR)/ipv4-address.o $(BUILDDIR)/fatal-impl.o $(BUILDDIR)/log.o $(BUILDDIR)/tag-buffer.o $(BUILDDIR)/address.o	
 
$(BUILDDIR)/RateDatabase.o: $(SOURCEDIR)/RateDatabase.h $(SOURCEDIR)/RateDatabase.cc $(SOURCEDIR)/$(NS3DIR)/ipv4-address.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/RateDatabase.o  $(SOURCEDIR)/RateDatabase.cc  
$(BUILDDIR)/UserDatabase.o:  $(SOURCEDIR)/$(NS3DIR)/UserDatabase.h $(SOURCEDIR)/$(NS3DIR)/UserDatabase.cc $(SOURCEDIR)/$(NS3DIR)/ipv4-address.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/UserDatabase.o  $(SOURCEDIR)/$(NS3DIR)/UserDatabase.cc
$(BUILDDIR)/attribute.o:  $(SOURCEDIR)/$(NS3DIR)/log.h $(SOURCEDIR)/$(NS3DIR)/attribute.h  $(SOURCEDIR)/$(NS3DIR)/fatal-error.h  $(SOURCEDIR)/$(NS3DIR)/string.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/attribute.o  $(SOURCEDIR)/$(NS3DIR)/attribute.cc
$(BUILDDIR)/string.o:  $(SOURCEDIR)/$(NS3DIR)/log.h $(SOURCEDIR)/$(NS3DIR)/string.cc $(SOURCEDIR)/$(NS3DIR)/attribute-helper.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/string.o  $(SOURCEDIR)/$(NS3DIR)/string.cc
$(BUILDDIR)/ipv4-address.o:  $(SOURCEDIR)/$(NS3DIR)/log.h $(SOURCEDIR)/$(NS3DIR)/assert.h  $(SOURCEDIR)/$(NS3DIR)/ipv4-address.cc  $(SOURCEDIR)/$(NS3DIR)/ipv4-address.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/ipv4-address.o  $(SOURCEDIR)/$(NS3DIR)/ipv4-address.cc
$(BUILDDIR)/tag-buffer.o:  $(SOURCEDIR)/$(NS3DIR)/log.h $(SOURCEDIR)/$(NS3DIR)/assert.h  $(SOURCEDIR)/$(NS3DIR)/tag-buffer.cc  $(SOURCEDIR)/$(NS3DIR)/tag-buffer.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/tag-buffer.o  $(SOURCEDIR)/$(NS3DIR)/tag-buffer.cc
$(BUILDDIR)/fatal-impl.o: $(SOURCEDIR)/$(NS3DIR)/core-config.h $(SOURCEDIR)/$(NS3DIR)/fatal-impl.h $(SOURCEDIR)/$(NS3DIR)/fatal-impl.cc $(SOURCEDIR)/$(NS3DIR)/log.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/fatal-impl.o $(SOURCEDIR)/$(NS3DIR)/fatal-impl.cc
$(BUILDDIR)/log.o:  $(SOURCEDIR)/$(NS3DIR)/log.h $(SOURCEDIR)/$(NS3DIR)/log.cc $(SOURCEDIR)/$(NS3DIR)/core-config.h $(SOURCEDIR)/$(NS3DIR)/fatal-error.h
	g++ $(DEBUG) -c -o $(BUILDDIR)/log.o  $(SOURCEDIR)/$(NS3DIR)/log.cc
$(BUILDDIR)/address.o:  $(SOURCEDIR)/$(NS3DIR)/log.h $(SOURCEDIR)/$(NS3DIR)/log.cc $(SOURCEDIR)/$(NS3DIR)/address.h $(SOURCEDIR)/$(NS3DIR)/address.cc
	g++ $(DEBUG) -c -o $(BUILDDIR)/address.o  $(SOURCEDIR)/$(NS3DIR)/address.cc
clean:
	rm $(BUILDDIR)/*o

