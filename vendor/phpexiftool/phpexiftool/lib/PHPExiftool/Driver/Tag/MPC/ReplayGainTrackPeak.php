<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\MPC;

use PHPExiftool\Driver\AbstractTag;

class ReplayGainTrackPeak extends AbstractTag
{

    protected $Id = 'Bit096-111';

    protected $Name = 'ReplayGainTrackPeak';

    protected $FullName = 'MPC::Main';

    protected $GroupName = 'MPC';

    protected $g0 = 'MPC';

    protected $g1 = 'MPC';

    protected $g2 = 'Audio';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Replay Gain Track Peak';

}
